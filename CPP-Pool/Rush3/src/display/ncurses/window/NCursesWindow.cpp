/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** NCursesWindow
*/

#include <cstdlib>
#include <unistd.h>
#include <string.h>

#include "NCursesWindow.hpp"
#include "TextModule.hpp"
#include "BarModule.hpp"
#include "MemoryModule.hpp"
#include "NetWorkModule.hpp"

NCursesWindow::NCursesWindow() : AMonitorDisplay()
{
    this->_win = initscr();
    this->_nbModules = 0;
    if (!has_colors()) {
        endwin();
        throw std::runtime_error("Your terminal does not support color for ncurses\n");
    }
    start_color();
    cbreak();
    keypad(_win, TRUE);
    noecho();
    nodelay(_win, TRUE);
    curs_set(0);
}

NCursesWindow::~NCursesWindow()
{
    for (ANCursesModules *m : _ncurse_modules)
        delete m;
    endwin();
}

void NCursesWindow::printModules()
{
    for (ANCursesModules *m : _ncurse_modules)
        if (m->isEnabled()) {
            m->getModule()->refresh();
            m->display();
        }
}

bool NCursesWindow::need_enlarge() const
{
    int row;
    int col;
    char msg[] = "Please enlarge the terminal :)\n";

    getmaxyx(stdscr, row, col);
    if (row < 27 || col < 80) {
        mvprintw(row / 2, (col - strlen(msg)) / 2, "%s", msg);
        getch();
        clear();
        return (true);
    }
    return (false); 
}

int getShiftAt(int index, std::map<int, int> &_shift)
{
    int shift = 0;

    for (int i = 0; i < index; i++)
        shift += _shift[i];
    return (shift);
}

void NCursesWindow::keyHandling(int ch)
{
    bool newb;
    int shift = 0;

    for (ANCursesModules *m : _ncurse_modules) {
        if (m->getKey() == ch) {
            newb = !(m->isEnabled());
            m->setEnabled(newb);
            this->_shift[m->getIndex()] = newb ? 0 : m->getSize();
        }
    }
    for (ANCursesModules *m : _ncurse_modules) {
        shift = getShiftAt(m->getIndex(), this->_shift);
        m->setCoords(m->getCol() - shift, 0);
    }
}

void NCursesWindow::main_loop(std::list<AMonitorModule *> modules)
{
    int ch = 0;

    this->init_modules(modules);
    while (true)
    {
        if (this->need_enlarge()) {
            sleep(1);
            continue;
        }
        ch = getch();
        this->keyHandling(ch);
        clear();
        this->printModules();
        refresh();
        sleep(1);
    }
}

void NCursesWindow::init_modules(std::list<AMonitorModule *> modules)
{
    for (AMonitorModule *mod : modules) {
        if (dynamic_cast<Uptime *>(mod)) {
            _ncurse_modules.push_back(new TextModule(0, 0, mod, 'a', 0, 2));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Username *>(mod)) {
            _ncurse_modules.push_back(new TextModule(2, 0, mod, 'z', 1, 2));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Hostname *>(mod)) {
            _ncurse_modules.push_back(new TextModule(4, 0, mod, 'e', 2, 2));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Time *>(mod)) {
            _ncurse_modules.push_back(new TextModule(6, 0, mod, 'r', 3, 3));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<System *>(mod)) {
            _ncurse_modules.push_back(new TextModule(9, 0, mod, 't', 4, 5));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Processor *>(mod)) {
            _ncurse_modules.push_back(new BarModule(14, 0, mod, 'y', 5, 6));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Memory *>(mod)) {
            _ncurse_modules.push_back(new MemoryModule(20, 0, mod, 'u', 6, 3));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
        if (dynamic_cast<Networking *>(mod)) {
            _ncurse_modules.push_back(new NetWorkModule(23, 0, mod, 'i', 7, 0));
            this->_shift.insert(std::pair<int,int>(this->_nbModules,0));
            this->_nbModules++;
        }
    }
}