/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "AEnemy.hpp"

AEnemy::AEnemy(int hp, const std::string &type)
{
    this->_hp = hp;
    this->_type = type;
}

AEnemy::~AEnemy()
{
}

void AEnemy::takeDamage(int damage)
{
    if (damage < 0)
        return;
    this->_hp -= damage;
}

std::string const &AEnemy::getType() const
{
    return (this->_type);
}

int AEnemy::getHP() const
{
    return (this->_hp);
}

