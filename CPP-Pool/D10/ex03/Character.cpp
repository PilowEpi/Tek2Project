/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "Character.hpp"

Character::Character(const std::string &name)
{
    this->_name = name;
}

Character::Character(const Character &other)
{
    this->_name = other._name;
    this->_size = other._size;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = other._inventory[i];
    }
}

Character::~Character()
{
    for (AMateria *unit : this->_inventory)
        delete unit;
}

std::string const &Character::getName() const
{
    return (this->_name);
}

void Character::equip(AMateria *m)
{
    if (this->_size == 4)
        return;
    for (AMateria *unit : this->_inventory) {
        if (!unit) {
            unit = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > 0 && idx < 3)
        return;
    this->_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx > 0 && idx < 3)
        return;
    if (!this->_inventory[idx])
        return;
    this->_inventory[idx]->use(target);
}

Character &Character::operator=(const Character &other)
{
    this->_name = other._name;
    this->_size = other._size;
    for (int i = 0; i < 4; i++) {
        this->_inventory[i] = other._inventory[i];
    }
    return (*this);
}