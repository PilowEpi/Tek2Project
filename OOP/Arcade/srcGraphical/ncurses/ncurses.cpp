
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <math.h>
#include <iostream>

#include "arcade.hpp"
#include "ncurses.hpp"

extern "C" int getLibType()
{
    return (0);
}

extern "C" NCurses* ctor()
{
    return new NCurses;
}

extern "C" std::string getLibName()
{
    return (std::string("ncurses"));
}

void NCurses::init(int x, int y)
{
    initscr();
    cbreak();
    noecho();
    nonl();
    intrflush(stdscr, 0);
    keypad(stdscr, 1);
    timeout(0);
    curs_set(0);

    if (!has_colors()) {
        endwin();
        throw GraphicError("this terminal does not support colors");
    }
    start_color();
    this->initColor();

    this->_x = x;
    this->_y = y;
    this->_name = "NCurses";
    this->_buff.resize(y, std::vector<NCursesBuffPixel>(x * 2));
    this->_hasInit = true;
}

void NCurses::initColor()
{
    for (int i = 0; i < 16; i++)
        for (int j = 0; j < 16; j++)
            init_pair(i + j * 16, i, j);
}

void NCurses::stop()
{
    endwin();
}

void NCurses::drawPixel(int x, int y, IDisplayModule::color_t color)
{
    if (x >= this->_x || y >= this->_y) {
        return; //throw GraphicError("drawPixel: try to draw out of bounds");
    }

    this->_buff[y][x * 2]._bg = color;
    this->_buff[y][x * 2 + 1]._bg = color;
    
    //this->_buff[y][x]._c = ' ';
}

IDisplayModule::color_t NCurses::convertColor(const Color c)
{
    std::vector<int> sums;

    for (int i = 0; i < 16; i++) {
        sums.push_back(abs(colors[i].r - c.r) +
                       abs(colors[i].g - c.g) +
                       abs(colors[i].b - c.b));
    }

    int max = 255 * 10;
    int idx = 0;

    for (int i = 0; i < 16; i++) {
        if (sums[i] < max) {
            idx = i;
            max = sums[i];
        }
    }
    
    return ((IDisplayModule::color_t) idx);
}

void NCurses::drawLine(Line *line)
{
    int dx = line->d.x;
    int dy = line->d.y;
    IDisplayModule::color_t color = this->convertColor(line->color);

    this->drawLineDx(line->pos.x, line->pos.y, dx, dy,
                     color);
}

void NCurses::drawLineDx(int x_, int y_, int dx_, int dy_,
                         IDisplayModule::color_t color)
{
    double x1 = (double) x_;
    double y1 = (double) y_;

    double x2 = (double) x_ + dx_;
    double y2 = (double) y_ + dy_;

    const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
    if (steep) {
        std::swap(x1, y1);
        std::swap(x2, y2);
    }
    
    if (x1 > x2) {
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
 
    const float dx = x2 - x1;
    const float dy = fabs(y2 - y1);
    
    float error = dx / 2.0f;
    const int ystep = (y1 < y2) ? 1 : -1;
    int y = (int)y1;
    
    const int maxX = (int)x2;
    
    for (int x=(int)x1; x < maxX; x++) {
        if (steep) {
            this->drawPixel(y, x, color);
        } else {
            this->drawPixel(x, y, color);
        }
 
        error -= dy;
        if (error < 0) {
            y += ystep;
            error += dx;
        }
    }
}

void NCurses::drawSquare(Square *sq)
{
    IDisplayModule::color_t color = this->convertColor(sq->color);

    for (int i = 0; i < sq->size.y; i++)
        this->drawLineDx(sq->pos.x, sq->pos.y + i, sq->size.x, 0, color);
}

void NCurses::drawText(Text *text)
{
    IDisplayModule::color_t color = this->convertColor(text->color);
    std::string txt = text->text;
    Vec2i pos = text->pos;

    for (int x = 0; x < int(txt.length()); x++) {
        this->_buff[pos.y][pos.x * 2 + x]._cl = color;
        this->_buff[pos.y][pos.x * 2 + x]._c = txt[x];
    }
}

void NCurses::drawShape(IObject* obj)
{
    Square *square = dynamic_cast<Square *>(obj);
    Line *line = dynamic_cast<Line *>(obj);
    Text *txt = dynamic_cast<Text *>(obj);

    if (!_hasInit)
        return;
    if (txt)
        this->drawText(txt);
    else if (square)
        this->drawSquare(square);
    else if (line)
        this->drawLine(line);
}

void NCurses::refresh()
{
    ::refresh();
    for (int i = 0; i < this->_y; i++) {
        for (int j = 0; j < this->_x * 2; j++) {
            int pair = this->_buff[i][j]._cl + this->_buff[i][j]._bg * 16;
            pair = COLOR_PAIR(pair);

            attron(pair);
            mvaddch(i, j, this->_buff[i][j]._c);
            attroff(pair);

            this->_buff[i][j]._cl = IDisplayModule::WHITE;
            this->_buff[i][j]._bg = IDisplayModule::BLACK;
            this->_buff[i][j]._c = ' ';
        }
    }
}

Event NCurses::getEvent()
{
    //struct termios old_termios;
    //struct termios new_termios;
    int ch;

    /*tcgetattr(STDIN_FILENO, &old_termios );
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    */
    ch = getch();
    //tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    return (Event(ch));
}
