/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <iostream>
#include <string>

#include "Droid.hpp"

Droid::Droid(std::string serial)
{
    this->_id = serial;
    this->_energy = 50;
    this->_status = new std::string("Standing by");
    this->_battleData = new DroidMemory;
    std::cout << "Droid '" << this->_id << "' Activated" << std::endl;
}

Droid::Droid(const Droid &other)
{
    this->_id = other._id;
    this->_energy = 50;
    this->_status = new std::string(other.getStatus());
    this->_battleData = new DroidMemory(*other.getBattleData());
    std::cout << "Droid '" << this->_id << "' Activated, Memory Dumped" << std::endl;
}

Droid::~Droid()
{
    if (this->_status)
        delete this->_status;
    std::cout << "Droid '" << this->_id << "' Destroyed" << std::endl;
}

// Getter

std::string Droid::getId() const
{
    return (_id);
}

size_t Droid::getEnergy() const
{
    return (_energy);
}

size_t Droid::getAttack() const
{
    return (_attack);
}

size_t Droid::getToughness() const
{
    return (_toughness);
}

std::string Droid::getStatus() const
{
    return (*_status);
}

DroidMemory *Droid::getBattleData() const
{
    return (_battleData);
}

// Setter

void Droid::setId(std::string id)
{
    this->_id = id;
}

void Droid::setEnergy(size_t energy)
{
    if (energy > 100) {
        this->_energy = 100;
    } else {
        this->_energy = energy;
    }
}

void Droid::setStatus(std::string *status)
{
    delete this->_status;
    this->_status = status;
}

void Droid::setBattleData(DroidMemory *battleData)
{
    if (this->_battleData)
        delete this->_battleData;
    this->_battleData = battleData;
}

// Operator

Droid &Droid::operator=(const Droid &other)
{
    this->_id = other._id;
    if (this->_status)
        delete this->_status;
    this->_status = new std::string (other.getStatus());
    if (this->_battleData)
        delete this->_battleData;
    this->_battleData = new DroidMemory (*other.getBattleData());
    this->_energy = other._energy;
    return (*this);
}

bool Droid::operator!=(const Droid &other) const
{
    if (this->getStatus() != other.getStatus())
        return (true);
    return (false);
}

bool Droid::operator==(const Droid &other) const
{
    if (this->getStatus() != other.getStatus())
        return (false);
    return (true);
}

Droid &operator<<(Droid &other, size_t &energy)
{
    size_t valueNeeded = 100 - other.getEnergy();

    if (valueNeeded == 0)
        return (other);
    if (valueNeeded == energy) {
        energy = 0;
        other.setEnergy(other.getEnergy() + valueNeeded);
        return (other);
    }
    if (valueNeeded > energy) {
        other.setEnergy(other.getEnergy() + energy);
        energy = 0;
        return (other);
    }
    if (valueNeeded < energy) {
        other.setEnergy(other.getEnergy() + valueNeeded);
        energy -= valueNeeded;
        return (other);
    }
    return (other);
}

std::ostream &operator<<(std::ostream &out, const Droid &droid)
{
    out << "Droid '" << droid.getId() << "', " << droid.getStatus() << ", " << droid.getEnergy();
    return out;
}

// () Operator

bool Droid::operator()(const std::string *task, size_t expRequired)
{
    size_t currentExp = this->getBattleData()->getExp();
    size_t currentEnergy = this->getEnergy();
    std::string finalTask = *task;
    std::string failed = " - Failed!";
    std::string completed = " - Completed!";

    this->setEnergy(currentEnergy - 10);
    if (currentEnergy - 10 <= 0) {
        this->setStatus(new std::string("Battery Low"));
        return false;
    }
    if (currentExp >= expRequired) {
        finalTask += completed;
        this->setStatus(new std::string(finalTask));
        this->getBattleData()->setExp(currentExp + (expRequired / 2));
        return true;
    } 
    finalTask += failed;
    this->setStatus(new std::string (finalTask));
    this->getBattleData()->setExp(currentExp + expRequired);
    return false;
}