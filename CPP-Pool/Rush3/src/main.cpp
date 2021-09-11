/*
** EPITECH PROJECT, 2021
** Rush3
** File description:
** main
*/

#include <iostream>

// HOSTNAME
#include <unistd.h>
#include <limits.h>

//SYS INFORMATIONS
#include <sys/utsname.h>

// TIME
#include <ctime>

// UPTIME
#include <chrono>
#include <fstream>

//Core & CPU
#include "sys/types.h"
#include "sys/sysinfo.h"
#include <thread>
#include <stdio.h>

#include "Username.hpp"
#include "Hostname.hpp"
#include "System.hpp"
#include "Time.hpp"
#include "Uptime.hpp"
#include "Processor.hpp"
#include "Memory.hpp"
#include "Networking.hpp"

#include <ncurses.h>
#include "AMonitorModule.hpp"
#include "NCursesWindow.hpp"
#include "sfml/display.hpp"

#include <stdlib.h>
#include <list>

void runGKrellm(bool sfml = false)
{
    std::list<AMonitorModule *> modules =
    {
        new Username,
        new Hostname,
        new Time,
        new Uptime,
        new System,
        new Processor,
        new Memory,
        new Networking
    };
    for (int i = 0; i < 3; i++) {
        for (AMonitorModule *m : modules) {
            try {
                m->refresh();
            } catch (std::exception &e) {
                std::cerr << "An exception occurred during refreshing :" << e.what() << std::endl;
                std::cerr << e.what() << std::endl;
            }
        }
    }

    if (sfml) {
        SfmlDisplay sfm;

        sfm.main_loop(modules);
    } else {
        NCursesWindow monitor;

        monitor.main_loop(modules);
    }
    for (AMonitorModule *m : modules)
        delete m;
}

int main(int ac, char **av)
{
    if (ac == 1)
        runGKrellm();
    else {
        if (std::string(av[1]) == "-h" || std::string(av[1]) == "--help") {
            std::cout << "How to use MyGKrellm:" << std::endl;
            std::cout << "\t-h / --help\tshow this message" << std::endl;
            std::cout << "\t-g open the sfml version" << std::endl;
        } else if (std::string(av[1]) == "-g") {
            runGKrellm(true);
        } else {
            runGKrellm(false);
        }
    }
    return 0;
}