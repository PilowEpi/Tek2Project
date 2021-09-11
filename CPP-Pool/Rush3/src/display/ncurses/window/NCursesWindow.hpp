/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** NcurseWindow
*/

#ifndef NCURSE_WIN_HPP_
#define NCURSE_WIN_HPP_

#include <ncurses.h>
#include <list>
#include <stdexcept>
#include <iostream>
#include <map>
#include "AMonitorDisplay.hpp"
#include "AMonitorModule.hpp"
#include "ANCursesModules.hpp"
#include "Uptime.hpp"
#include "Username.hpp"
#include "Hostname.hpp"
#include "Time.hpp"
#include "System.hpp"
#include "Networking.hpp"
#include "Processor.hpp"

class NCursesWindow : public AMonitorDisplay {
    public:
        NCursesWindow();
        ~NCursesWindow();
        WINDOW * getWindow() const { return _win; };
        void refreshModules();
        void printModules();
        void main_loop(std::list<AMonitorModule *> modules) override;
        
    protected:
        WINDOW *_win;
        std::list<ANCursesModules *> _ncurse_modules;
        std::map<int, int> _shift;
        int _nbModules;

    private:
        void keyHandling(int ch);
        bool need_enlarge() const;
        void init_modules(std::list<AMonitorModule *> modules);
};

#endif