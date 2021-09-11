/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include "Character.hpp"
#include "Warrior.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"

Paladin::Paladin(const std::string &name, int level, const std::string &weaponName)
        :Character(name, level), Warrior(name, level, weaponName), Priest(name, level)
{
    this->_strength = 9;
    this->_stamina = 10;
    this->_intelligence = 10;
    this->_spirit = 10;
    this->_agility = 2;

    std::cout << this->Warrior::getName() << " the light falls on" << std::endl;

}

int Paladin::CloseAttack()
{
    return (this->Warrior::CloseAttack());
}

int Paladin::RangeAttack()
{
    return (this->Priest::RangeAttack());
}

void Paladin::Heal()
{
    return (this->Priest::Heal());
}

void Paladin::RestorePower()
{
    return (this->Warrior::RestorePower());
}

int Paladin::Intercept()
{
    return (this->Warrior::RangeAttack());
}