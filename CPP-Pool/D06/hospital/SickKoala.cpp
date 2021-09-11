/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>
#include <string>

#include "SickKoala.hpp"

SickKoala::~SickKoala()
{
    std::cout << "Mr." << this->_name << ": Kreooogg!! I'm cuuuured!" << std::endl;
}

SickKoala::SickKoala(std::string name) 
{
    this->_name = name;
}

void SickKoala::poke()
{
    std::cout << "Mr." << this->_name << ": Gooeeeeerrk!!" << std::endl;
}

bool SickKoala::takeDrug(std::string drugName)
{
    if (drugName == "Mars") {
        std::cout << "Mr." << this->_name << ": Mars, and it kreogs!" << std::endl;
        return (true);
    } else if (drugName == "Kinder") {
        std::cout << "Mr." << this->_name << ": There is a toy inside" << std::endl;
        return (true);
    }
    std::cout << "Mr." << this->_name << ": Goerkreog!" << std::endl;
    return (false);
}

void SickKoala::overDrive(std::string question)
{
    std::string to_find = "Kreog!";

    int result = question.find(to_find);

    if (result != -1)
        question.replace(result, to_find.length(), "1337!");
    std::cout << "Mr." << this->_name << ": "<< question << std::endl;
}