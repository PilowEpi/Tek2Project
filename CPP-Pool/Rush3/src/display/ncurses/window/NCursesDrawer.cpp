/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NCursesDrawer
*/

#include "NCursesDrawer.hpp"

/*

Color Dictionary:

0 : White   / Black
1 : Green   / Black
2 : Red     / Black
3 : Cyan    / Black
4 : Blue    / Black
5 : Yellow   / Black

6 : 

*/

NCursesDrawer::NCursesDrawer()
{
    init_pair(0, COLOR_WHITE, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_CYAN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);
    
    init_pair(6, COLOR_BLACK, COLOR_WHITE);
    this->_color_id = 0;
}

void NCursesDrawer::setColor(int color_id)
{
    this->_color_id = color_id;
}

void NCursesDrawer::drawText(int col, int row, std::string text)
{
    attron(COLOR_PAIR(this->_color_id));
    mvprintw(col, row, text.c_str());
    attroff(COLOR_PAIR(this->_color_id));
}

void NCursesDrawer::drawChar(int col, int row, char c)
{
    char str[2];
    str[0] = c;    
    
    attron(COLOR_PAIR(this->_color_id));
    mvprintw(col, row, str);
    attroff(COLOR_PAIR(this->_color_id));
}

void NCursesDrawer::drawBar(int col, int row, int size, float local, float system)
{
    int bar_size = size - 2;
    int bar_local = local * bar_size;
    int bar_system = system * bar_size;
    int bar_wide = bar_size - (bar_local + bar_system);
    int pos = 1;

    this->setColor(0);
    this->drawChar(col, row, '[');
    this->setColor(1);
    for (int i = 0; i < bar_local; i++, pos++) {
        this->drawChar(col, row + pos, '|');
    }
    this->setColor(2);
    for (int i = 0; i < bar_system; i++, pos++) {
        this->drawChar(col, row + pos, '|');
    }
    this->setColor(0);
    for (int i = 0; i < bar_wide; i++, pos++) {
        this->drawChar(col, row + pos, ' ');
    }
    this->drawChar(col, row + pos, ']');
    pos++;
}

void NCursesDrawer::drawPercent(int col, int row, float percentage)
{
    std::ostringstream stream;

    stream << std::fixed;
    stream << std::setprecision(2) << percentage << "%%";

    this->drawText(col, row, stream.str().c_str());
}

void NCursesDrawer::drawFullBar(int col, int row, int size, std::string label, float local, float system)
{
    std::ostringstream stream;
    int strSize = 0;

    stream << label << " :";
    strSize = stream.str().length();
    this->drawText(col, row, stream.str().c_str());
    this->drawBar(col, row + strSize, size, local, system);
    this->drawPercent(col, row + strSize + size, (local * 100) + (system * 100));
}