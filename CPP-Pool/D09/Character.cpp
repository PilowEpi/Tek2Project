/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include "Character.hpp"

Character::Character(const std::string &name, int level)
{
    this->_name = name;

    this->_level = level;
    this->_pv = 100;
    this->_power = 100;
    this->Range = Character::CLOSE;

    this->_strength = 5;
    this->_stamina = 5;
    this->_intelligence = 5;
    this->_spirit = 5;
    this->_agility = 5;

    std::cout << this->getName() << " Created" << std::endl;
}

Character::~Character()
{
}

// getter

const std::string &Character::getName() const
{
    return (this->_name);
}

int Character::getLvl() const
{
    return (this->_level);
}

int Character::getPv() const
{
    return (this->_pv);
}

int Character::getPower() const
{
    return (this->_power);
}

// setter

void Character::setPv(int pv)
{
    if (pv > 100)
        this->_pv = 100;
    else
        this->_pv = pv;
}

void Character::setPower(int power)
{
    this->_power = power;
}

// tech

int Character::CloseAttack()
{
    int cost = 10;
    int dmg = 10 + this->_strength;
    std::string output = this->getName() + " strikes with a wooden stick";

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

void Character::Heal()
{
    int heal = 50;
    std::string output = this->getName() + " takes a potion";

    std::cout << output << std::endl;
    this->setPv(this->getPv() + heal);
}

int Character::RangeAttack()
{
    int cost = 10;
    int dmg = 5 + this->_strength;
    std::string output = this->getName() + " tosses a stone";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}

void Character::RestorePower()
{
    std::string output = this->getName() + " eats";

    this->setPower(100);
    std::cout << output << std::endl;
}

void Character::TakeDamage(int damage)
{
    this->setPv(this->getPv() - damage);

    if (this->getPv() > 0)
        std::cout << this->getName() << " takes " << damage << " damage" << std::endl;
    else
        std::cout << this->getName() << " out of combat" << std::endl;
}