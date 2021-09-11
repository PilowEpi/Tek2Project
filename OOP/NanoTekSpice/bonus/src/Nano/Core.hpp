/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** core.hpp
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <unistd.h>
#include <csignal>

#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <unistd.h>


#include "Nano.hpp"
#include "Error.hpp"
#include "AComponent.hpp"

#define is_print(x) (x >= 32 && x < 127)

class Core {
public:
    ~Core();
    Core(const std::string &filename);

    //Methods
    int shell();
    int commandExec(const std::string &command);
    static void signal_sigint_handler(__attribute__((unused)) int signum);

    //Commands
    void assign(const std::string &command);
    void refreshDisplay();
    void display();
    void simulate();
    void loop();
    void dump();


    /*
    ** BONUS SHELL
    */

    // Init
    void ttyShell();
    void ownShell();
    int myGetchar();

    int checkKey();
    int getCode();
    void reset();

    // Arrow 
    int getArrow();
    void printnext(int spaces);
    int rightArrow();
    int leftArrow();
    int historyArrow(int arrow);

    // Tabulations
    void tabulation();
    void setupPin();

    // Comand
    void printHistory();
    void clearShell();

private:
    // Bonus Shell var
    std::vector<std::string> _history;
    int index;
    std::string _commands;

    int cursor;
    int c;

    std::vector<std::string> _obj;
    int _indexObj;

    // Base Shell var
    std::string _prompt;
    std::ostringstream _buff;
    int _exitValue;
    int _ticks;

    Nano *_nano;
};


#endif //CORE_HPP_
