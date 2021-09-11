/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include "Character.hpp"
#include "Mage.hpp"

Mage::Mage(const std::string &name, int level)
    :Character(name, level)
{
    this->_strength = 6;
    this->_stamina = 6;
    this->_intelligence = 12;
    this->_spirit = 11;
    this->_agility = 7;

    std::cout << this->getName() << " teleported" << std::endl;
}

int Mage::CloseAttack()
{
    int cost = 10;
    int dmg = 0;
    std::string output = this->getName() + " blinks";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->Range = RANGE;
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}

int Mage::RangeAttack()
{
    int cost = 25;
    int dmg = 20 + this->_spirit;
    std::string output = this->getName() + " launches a fire ball";

    if (this->getPower() - cost < 0) {
        std::cout << this->getName() << " out of power" << std::endl;
        return (0);
    }
    this->setPower(this->getPower() - cost);
    std::cout << output << std::endl;
    return (dmg);
}

void Mage::RestorePower()
{
    int total = this->getPower() + 50 + this->_intelligence;
    std::string output = this->getName() + " takes a mana potion";

    if (total > 100)
        this->setPower(100);
    else
        this->setPower(total);
    std::cout << output << std::endl;
}
