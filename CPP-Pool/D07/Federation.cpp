/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>

#include "Destination.hpp"
#include "Federation.hpp"

// Captain

Federation::Starfleet::Captain::Captain(std::string name)
{
    this->_name = name;
    this->_age = 0;    
}

Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
    return (this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
    return (this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
    if (age < 0)
        return;
    this->_age = age;
}

// Ensign

Federation::Starfleet::Ensign::Ensign(std::string name)
{
    this->_name = name;
    std::cout << "Ensign " << this->_name << ", awaiting orders." << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
}

// Starfleet

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short maxWarp)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = maxWarp;
    this->_home = EARTH;
    this->_location = this->_home;

    std::cout << "The ship USS " << this->_name << " has been finished." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
    if (this->_maxWarp != 0) {
        std::cout << "It can go to Warp " << this->_maxWarp << "!" << std::endl;
    }
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable() == true) {
        std::cout << "USS " << this->_name << ": The core is stable at the time." << std::endl;
    } else {
        std::cout << "USS " << this->_name << ": The core is unstable at the time." << std::endl;
    }
}

void Federation::Starfleet::Ship::promote(Captain *captain)
{
    if (captain == nullptr)
        return;
    this->_captain = captain;
    std::cout << this->_captain->getName() << ": I'm glad to be the captain of the USS " << this->_name << "." <<std::endl;
}

// Staarfleet Ship
// Move

bool Federation::Starfleet::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp) {
        if (d != this->_location) {
            if (this->_core->checkReactor()->isStable() == true) {
                this->_location = d;
                return (true);
            }
        }
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(int warp)
{
    if (warp <= this->_maxWarp) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Starfleet::Ship::move(Destination d)
{
    if (d != this->_location) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Starfleet::Ship::move()
{
    if (this->_core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}

// Federation

Federation::Ship::Ship(int length, int width, std::string name)
{
    this->_length = length;
    this->_width = width;
    this->_name = name;
    this->_maxWarp = 1;
    this->_home = VULCAN;
    this->_location = this->_home;

    std::cout << "The independent ship " << this->_name << " just finished its construction." << std::endl;
    std::cout << "It is " << this->_length << " m in length and " << this->_width << " m in width." << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *core)
{
    this->_core = core;
    std::cout << this->_name << ": The core is set." << std::endl;
}

void Federation::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable() == true) {
        std::cout << this->_name << ": The core is stable at the time." << std::endl;
    } else {
        std::cout << this->_name << ": The core is unstable at the time." << std::endl;
    }
}
// Federation Ship
// Move

bool Federation::Ship::move(int warp, Destination d)
{
    if (warp <= this->_maxWarp) {
        if (d != this->_location) {
            if (this->_core->checkReactor()->isStable() == true) {
                this->_location = d;
                return (true);
            }
        }
    }
    return (false);
}

bool Federation::Ship::move(int warp)
{
    if (warp <= this->_maxWarp) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Ship::move(Destination d)
{
    if (d != this->_location) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Federation::Ship::move()
{
    if (this->_core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}