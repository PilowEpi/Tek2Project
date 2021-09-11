/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>
#include <fstream>
#include <string>

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name)
{
    this->_name = name;
    this->_isWorking = false;
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *koala)
{
    std::string drugs[] = {
        "Mars", "Kinder", "Crunch", "Maroilles", "Eucalyptus leaf"
    };
    int choose = rand() % 5;
    std::string fileName = koala->_name + ".report";
    std::fstream file;

    file.open(fileName, std::fstream::out);
    if (!file) {
        std::cout << "Error" << std::endl;
        return;
    }
    
    std::cout << "Dr." << this->_name << ": So what's goerking you Mr." << koala->_name << "?" << std::endl;
    koala->poke();
    file << drugs[choose];

}

void KoalaDoctor::timeCheck()
{
    this->_isWorking = !this->_isWorking;
    if (this->_isWorking) {
        std::cout << "Dr." << this->_name << ": Time to get to work!" << std::endl;
    } else {
        std::cout << "Dr." << this->_name << ": Time to go home to my eucalyptus forest!" << std::endl;
    }
}

std::string KoalaDoctor::getName()
{
    return (this->_name);
}