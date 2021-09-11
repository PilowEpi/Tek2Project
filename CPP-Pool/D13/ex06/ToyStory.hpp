/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef TOY_STORY_HPP_
#define TOY_STORY_HPP_

#include <iostream>
#include <string>
#include <fstream>

#include "Toy.hpp"

class ToyStory : public Toy
{
    public:
        static void tellMeAStory(std::string const &fileName, 
                        Toy &toy1, bool(Toy::*func1)(const std::string &),
                        Toy &toy2, bool(Toy::*func2)(const std::string &));
    private:
};


bool checkLine(std::string const &line)
{
    std::string toCheck = "picture:";
    for (int i = 0; i < toCheck.length(); i++)
        if (line[i] != toCheck[i])
            return false;
    return true;
}

void ToyStory::tellMeAStory(std::string const &fileName, 
                            Toy &toy1, bool (Toy::*func1)(const std::string &),
                            Toy &toy2, bool (Toy::*func2)(const std::string &))
{
    std::fstream fileData;
    std::string line;
    bool _isOne = true;

    if (fileName == "") {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    
    fileData.open(fileName, std::ios::in);
    
    if (!fileData) {
        std::cout << "Bad Story" << std::endl;
        return;
    }
    
    std::cout << toy1.getAscii() << std::endl;
    std::cout << toy2.getAscii() << std::endl;
    
    while (getline(fileData, line)) {
        if (checkLine(line) == true) {
            if (!((_isOne)? toy1.setAscii(&line[8]) : toy2.setAscii(&line[8]))) {
                auto error = (_isOne) ? toy1.getLastError() : toy2.getLastError();
                std::cout << error.where() << ": " << error.what() << std::endl;
                return;
            }
            std::cout << ((_isOne)? toy1.getAscii() : toy2.getAscii());
            _isOne = !_isOne;
        } else {
            if (!((_isOne)? (toy1.*func1)(line) : (toy2.*func2) (line))) {
                auto error = (_isOne) ? toy1.getLastError() : toy2.getLastError();
                std::cout << error.where() << ": " << error.what() << std::endl;
                return;
            }
        }
        _isOne = !_isOne;
    }
}

#endif