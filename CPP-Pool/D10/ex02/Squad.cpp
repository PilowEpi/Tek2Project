/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "Squad.hpp"

Squad::Squad(const Squad &other)
{
    for (ISpaceMarine *unit : other._units)
        this->push(unit);
}

Squad::~Squad()
{
    for (ISpaceMarine *unit : this->_units)
        delete unit;
}

Squad &Squad::operator=(const Squad &other)
{
    this->~Squad();
    for (ISpaceMarine *unit : other._units)
        this->push(unit);
    return (*this);
}

int Squad::getCount() const
{
    return (this->_units.size());
}

ISpaceMarine *Squad::getUnit(int index)
{
    if (index >= this->getCount() || index < 0)
        return (0);
    return (this->_units[index]);
}

int Squad::push(ISpaceMarine *spaceMarine)
{
    if (spaceMarine == NULL)
        return (this->_units.size());
    for (ISpaceMarine *unit : _units) {
        if (spaceMarine == unit)
            return (this->_units.size());
    }
    this->_units.push_back(spaceMarine);
    return (this->_units.size());
}

