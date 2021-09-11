/*
** EPITECH PROJECT, 2021
** Core.cpp
** File description:
** core.cpp
*/

#include "Core.hpp"

Core::~Core()
{
    delete this->_nano;
}

Core::Core(const std::string &filename)
{
    this->_prompt = "> ";
    this->_exitValue = 0;
    this->_ticks = 0;
    this->_nano = new Nano(filename);
    shell();
}

int Core::shell()
{
    std::string buffer;

    std::cout << this->_prompt;
    simulate();
    this->_ticks = 0;
    this->refreshDisplay();
    while (std::getline(std::cin, buffer)) {
        if (!buffer.empty()) {
            this->_exitValue = 0;
            if (commandExec(buffer) == 1)
                break;
        }
        std::cout << this->_prompt;
    }
    return this->_exitValue;
}

int Core::commandExec(const std::string &command)
{
    switch (switchPrep(command)) {
        case 0:
            assign(command);
            break;
        case 1 :
            return (1);
        case 2 :
            display();
            break;
        case 3 :
            simulate();
            break;
        case 4 :
            loop();
            break;
        case 5 :
            dump();
            break;
        default :
            std::cout << "Invalid Command" << std::endl;
            break;
    }
    return (0);
}

int Core::switchPrep(const std::string &command)
{
    if (command.find_first_of('=') != std::string::npos) return 0;
    if (command == "exit") return 1;
    if (command == "display") return 2;
    if (command == "simulate") return 3;
    if (command == "loop") return 4;
    if (command == "dump") return 5;
    return -1;
}