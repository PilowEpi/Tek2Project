/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include "Character.hpp"
#include "Priest.hpp"

Priest::Priest(const std::string &name, int level)
    :Character(name, level), Mage(name, level)
{
    this->_strength = 4;
    this->_stamina = 4;
    this->_intelligence = 42;
    this->_spirit = 21;
    this->_agility = 2;

    std::cout << this->getName() << " enters in the order" << std::endl;
}

int Priest::CloseAttack()
{
    int cost = 10;
    int dmg = 10 + this->_spirit;
    std::string output = this->getName() + " uses a spirit explosion";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    if (this->Range == RANGE)
        return (0);
    this->Range = RANGE;
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}

void Priest::Heal()
{
    int cost = 10;
    int heal = 70;
    std::string output = this->getName() + " casts a little heal spell";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return;
    }
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    this->setPv(this->getPv() + heal);
}