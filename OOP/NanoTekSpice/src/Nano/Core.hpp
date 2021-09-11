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

#include "Nano.hpp"
#include "Error.hpp"
#include "AComponent.hpp"

class Core {
public:
    ~Core();
    Core(const std::string &filename);

    //Methods
    int shell();
    static int switchPrep(std::string const& command);
    int commandExec(const std::string &command);
    static void signal_sigint_handler(__attribute__((unused)) int signum);

    //Commands
    void assign(const std::string &command);
    void refreshDisplay();
    void display();
    void simulate();
    void loop();
    void dump();

private:
    std::string _prompt;
    std::ostringstream _buff;
    int _exitValue;
    int _ticks;

    Nano *_nano;
};


#endif //CORE_HPP_
