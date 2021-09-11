/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Parts.hpp"

// Arms Parts

Arms::Arms(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_isFunctional = functional;
}

bool Arms::isFunctional() const
{
    return (_isFunctional);
}

std::string Arms::serial()
{
    return (this->_serial);
}

void Arms::informations() const
{
    std::string functional = (_isFunctional == true) ? "OK" : "KO";
    std::cout << "\t[Parts] Arms " << _serial << " status : " << functional << std::endl;
}

// Legs Parts

Legs::Legs(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_isFunctional = functional;
}

bool Legs::isFunctional() const
{
    return (_isFunctional);
}

std::string Legs::serial()
{
    return (this->_serial);
}

void Legs::informations() const
{
    std::string functional = (_isFunctional == true) ? "OK" : "KO";
    std::cout << "\t[Parts] Legs " << _serial << " status : " << functional << std::endl;
}
// Head Parts

Head::Head(std::string serial, bool functional)
{
    this->_serial = serial;
    this->_isFunctional = functional;
}

bool Head::isFunctional() const
{
    return (this->_isFunctional);
}

std::string Head::serial()
{
    return (this->_serial);
}

void Head::informations() const
{
    std::string functional = (_isFunctional == true) ? "OK" : "KO";
    std::cout << "\t[Parts] Head " << _serial << " status : " << functional << std::endl;
}

