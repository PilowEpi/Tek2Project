/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <string>

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"
#include "Destination.hpp"

Borg::Ship::Ship()
{
    this->_side = 300;
    this->_maxWarp = 0;
    this->_home = UNICOMPLEX;
    this->_location = this->_home;

    std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
    std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
    std::cout << "Resistance is futile." << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *core)
{
   this->_core = core; 
}

void Borg::Ship::checkCore()
{
    if (this->_core->checkReactor()->isStable() == true) {
        std::cout << "Everything is in order." << std::endl;
    } else {
        std::cout << "Critical failure imminent." << std::endl;
    }
}

//  Move

bool Borg::Ship::move(int warp, Destination d)
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

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (d != this->_location) {
        if (this->_core->checkReactor()->isStable() == true) {
            this->_location = this->_home;
            return (true);
        }
    }
    return (false);
}

bool Borg::Ship::move()
{
    if (this->_core->checkReactor()->isStable() == true) {
        this->_location = this->_home;
        return (true);
    }
    return (false);
}