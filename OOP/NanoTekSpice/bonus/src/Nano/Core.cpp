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
    this->cursor = 0;
    this->_commands = "";
    this->index = 0;
    this->_indexObj = 0;
    shell();
}

int Core::commandExec(const std::string &command)
{
    std::map<std::string, std::function<void()>> functors;

    functors = {{"history", [&](){printHistory();}},
                {"loop", [&](){loop();}},
                {"simulate", [&](){simulate();}},
                {"display", [&](){display();}},
                {"clear", [&](){clearShell();}},
                {"dump", [&](){dump();}}};

    if (command.find_first_of('=') != std::string::npos) {
        this->assign(command);
        return 0;
    } else if (command == "exit") {
        return 1;
    }
    
    auto cmd = functors.find(command);
    if (cmd == functors.end()) {
        std::cout << "Invalid Command" << std::endl;
        return 0;
    }
    functors[command]();
    return 0;
}