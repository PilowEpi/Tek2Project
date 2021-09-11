/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "AWeapon.hpp"

AWeapon::AWeapon(const std::string &name, int apcost, int damage)
{
    this->_name = name;
    this->_damage = damage;
    this->_action_points = apcost;
}

AWeapon::~AWeapon()
{
}

std::string const &AWeapon::getName() const
{
    return (this->_name);
}

int AWeapon::getDamage() const
{
    return (this->_damage);
}

int AWeapon::getAPCost() const
{
    return (this->_action_points);
}