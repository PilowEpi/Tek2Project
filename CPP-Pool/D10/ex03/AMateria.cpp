/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "AMateria.hpp"

AMateria::AMateria(const std::string& type)
{
    this->_type = type;
    this->_xp = 0;
}

AMateria::AMateria(const AMateria &other)
{
    this->_type = other._type;
    this->_xp = other._xp;
}

AMateria::~AMateria()
{
}

const std::string &AMateria::getType() const
{
    return (this->_type);
}

unsigned int AMateria::getXP() const
{
    return (this->_xp);
}

void AMateria::use(ICharacter &target)
{
    this->_xp = this->_xp + 10;
}

AMateria &AMateria::operator=(const AMateria &other)
{
    this->_xp = other._xp;
    return (*this);
}