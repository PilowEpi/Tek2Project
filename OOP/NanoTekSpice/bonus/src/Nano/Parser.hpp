/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** Parser
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

#include "Error.hpp"

class Parser
{
    public:
        enum Mode {
            CHIPSET,
            LINKS,
            NONE
        };
        Parser(const std::string &filename);
        ~Parser() {}; // TO DO
        std::map<std::string, std::string> getComponent() const { return _components; };
        std::map<std::string, std::string> getLinks() const { return _links; };
    private:
        void readFile(const std::string &filename);
        bool checkMode(const std::string &line);
        void parserLine(const std::string &line);

        Mode _mode;
        std::map<std::string, std::string> _components;
        std::map<std::string, std::string> _links;
};

#endif