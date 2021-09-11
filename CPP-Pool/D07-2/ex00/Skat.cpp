/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Skat.hpp"

Skat::Skat(const std::string &name , int stimPaks)
{
    this->_name = name;
    this->_stimPaks = stimPaks;
}

Skat::~Skat()
{
}

unsigned int &Skat::stimPaks()
{
    return (this->_stimPaks);
}

const std::string &Skat::name()
{
    return (this->_name);
}

void Skat::shareStimPaks(unsigned int number, unsigned int &stock)
{
    if (number > this->_stimPaks) {
        std::cout << "Don't be greedy" << std::endl;
    } else {
        this->_stimPaks -= number;
        stock += number;
        std::cout << "Keep the change." << std::endl;
    }
}

void Skat::addStimPaks(unsigned int number)
{
    if (number == 0) {
        std::cout << "Hey boya, did you forget something?" << std::endl;
        return;
    }
    this->_stimPaks += number;
}

void Skat::useStimPaks()
{
    if (this->_stimPaks == 0) {
        std::cout << "Mediiiiiic" << std::endl;
        return;
    }
    this->_stimPaks--;
    std::cout << "Time to kick some ass and chew bubble gum." << std::endl;
}

void Skat::status()
{
    std::cout << "Soldier " << this->_name << " reporting " << this->_stimPaks << " stimpaks remaining sir!" << std::endl;
}