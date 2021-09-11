/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include "Warrior.hpp"
#include "Character.hpp"

Warrior::Warrior(const std::string &name, int level, const std::string &weaponName)
        :Character(name, level)
{
    this->_strength = 12;
    this->_stamina = 12;
    this->_intelligence = 6;
    this->_spirit = 5;
    this->_agility = 7;

    this->_weaponName = weaponName;

    std::cout << "I'm " << this->getName() << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" << std::endl;
}

// Getter

std::string Warrior::getWeaponName() const
{
    return (this->_weaponName);
}

// tech

int Warrior::CloseAttack()
{
    int cost = 30;
    int dmg = 20 + this->_strength;
    std::string output = this->getName() + " strikes with his " + this->getWeaponName();

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    if (this->Range == RANGE)
        return (0);
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}

int Warrior::RangeAttack()
{
    int cost = 10;
    int dmg = 5 + this->_strength;
    std::string output = this->getName() + " intercepts";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    if (this->Range == CLOSE)
        return (0);
    this->Range = CLOSE;
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}