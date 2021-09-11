/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "Character.hpp"
#include "AWeapon.hpp"
#include "AEnemy.hpp"

Character::Character(const std::string &name)
{
    this->_name = name;
    this->_ap = 40;
    this->_weapon = 0;
}

Character::~Character()
{
}

void Character::recoverAP()
{
    if (this->_ap == 40)
        return;
    this->_ap = this->_ap + 10;
    if (this->_ap > 40)
        this->_ap = 40;
}

void Character::equip(AWeapon *weapon)
{
    this->_weapon = weapon;
}

void Character::attack(AEnemy *enemy)
{
    int cost = 0;
    int dmg = 0;

    if (!enemy)
        return;
    if (!this->_weapon)
        return;
    cost = this->_weapon->getAPCost();
    dmg = this->_weapon->getDamage();
    if (this->_ap - cost < 0)
        return;
    this->_ap = this->_ap - cost;
    std::cout << this->_name << " attacks " << enemy->getType() << " with a " << this->_weapon->getName() << std::endl;
    this->_weapon->attack();
    enemy->takeDamage(dmg);
    if (enemy->getHP() < 0)
        delete enemy;

}

// Getter

std::string const &Character::getName() const
{
    return (this->_name);
}

int Character::getAP() const
{
    return (this->_ap);
}

AWeapon const *Character::getWeapon() const
{
    return (this->_weapon);
}

// out

std::ostream &operator<<(std::ostream &out, const Character &character)
{
    if (character.getWeapon() != 0)
        out << character.getName() << " has " << character.getAP() << " AP and wields a " << character.getWeapon()->getName() << std::endl;
    else
        out << character.getName() << " has " << character.getAP() << " AP and is unarmed" << std::endl;
    return (out);
}
