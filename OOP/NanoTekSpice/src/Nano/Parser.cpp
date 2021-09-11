/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** Parser
*/

#include "Parser.hpp"

Parser::Parser(const std::string &filename)
{
    this->_mode = NONE;
    this->readFile(filename);
}

std::string cleanLine(std::string line)
{
    std::ostringstream stream("");

    for (size_t i = 0; i < line.length(); i++) {
        if (line[i] != ' ' && line[i] != '\t') {
            stream << &line[i];
            return (stream.str());
        }
    }
    return (stream.str());
}

void deleteComment(std::string &line)
{
    std::ostringstream stream("");

    for (size_t i = 0; i < line.length() && line[i] != '#'; i++)
            stream << line[i];
    line = stream.str();
}

void cleanBackLine(std::string &line)
{
    std::ostringstream stream("");
    int i = line.length() - 1;

    while (i > 0) {
        if (line[i] != ' ' && line[i] != '\t')
            break;
        i--;
    }
    for (int j = 0; j <= i; j++)
        stream << line[j];
    line = stream.str();
}

bool Parser::checkMode(const std::string &line)
{
    if (line == ".chipsets:") {
        this->_mode = CHIPSET;
        return (true);
    } else if (line == ".links:") {
        this->_mode = LINKS;
        return (true);
    }
    return (false);
}

void Parser::readFile(const std::string &filename)
{
    std::fstream file;
    std::string line;

    file.open(filename, std::ios::in);
    if (!file)
        throw FileError("Couldn't open file\n");
    while (getline(file, line)) {
        line = cleanLine(line);
        deleteComment(line);
        cleanBackLine(line);
        if (line.length() == 0 || this->checkMode(line))
            continue;
        this->parserLine(line);
    }
    file.close();
}

void Parser::parserLine(const std::string &line)
{
    std::string firstOption;
    std::string lastOption;
    int pos = line.find(" ");
    int posTab = line.find("\t");

    if (pos == -1 && posTab == -1)
        throw FileError ("parserLine: Invalid statement\n");
    if (pos == -1) {
        firstOption = line.substr(0, posTab);
        lastOption = line.substr(posTab+1, line.length());
    } else {
        firstOption = line.substr(0, pos);
        lastOption = line.substr(pos+1, line.length());
    }
    switch (this->_mode) {
        case NONE:
            throw FileError ("parserLine: Undefined mode for statement\n");
        case CHIPSET:
            this->_components.insert({lastOption, firstOption});
            break;
        case LINKS:
            this->_links.insert({firstOption, lastOption});
            break;
    };
}