/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <string>
#include <iostream>

#include "Carrier.hpp"

// Ctor

Carrier::Carrier(std::string id)
{
    this->_id = id;
    this->_energy = 300;
    this->_speed = 0;
    this->_numberOfDroid = 0;
}

//      Setter

void Carrier::setSpeed(size_t speed)
{
    this->_speed = speed;
}

void Carrier::setEnergy(size_t energy)
{
    this->_energy = energy;
}


//      Getter

size_t Carrier::getSpeed() const
{
    return (this->_speed);
}

size_t Carrier::getEnergy() const
{
    return (this->_energy);
}

Droid *const*Carrier::getDroid() const
{
    return (this->_droids);
}

// Speed Calculator

size_t Carrier::calculSpeed(size_t numberOfDroid) const
{
    size_t speed = 0;
    if (numberOfDroid > 0)
        speed += 100;
    speed -= 10 * numberOfDroid;
    return (speed);
}

void Carrier::setNumberOfDroid(size_t numberOfDroid)
{
    this->_numberOfDroid = numberOfDroid;
}

size_t Carrier::getNumberOfDroid() const
{
    return this->_numberOfDroid;
}

//      Asign

void Carrier::assignDroidToCarrier(size_t pos, Droid &droid)
{
    Droid *const* droidStock = this->getDroid();

    *droidStock[pos] = droid;
}


//      Operator

Carrier &operator<<(Carrier &carrier, Droid &droid)
{
    size_t numberOfDroid = carrier.getNumberOfDroid();

    if (numberOfDroid == 5)
        return (carrier);
    
    if (numberOfDroid == 0) {
        carrier.assignDroidToCarrier(0, droid);
    }

    carrier.setNumberOfDroid(numberOfDroid + 1);
}

Carrier &operator>>(Carrier &carrier, Droid &droid)
{
    size_t numberOfDroid = carrier.getNumberOfDroid();
    Droid * const* droidStocked = 0;

    if (numberOfDroid == 0)
        return (carrier);
    droidStocked = carrier.getDroid();

    carrier.setNumberOfDroid(numberOfDroid - 1);
}

