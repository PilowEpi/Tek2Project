/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>

#include "KoalaBot.hpp"
#include "Parts.hpp"

KoalaBot::KoalaBot(std::string serial)
{
    this->_serial = serial;
}

void KoalaBot::setParts(Arms &arms)
{
    this->_arms = arms;
}

void KoalaBot::setParts(Legs &legs)
{
    this->_legs = legs;
}

void KoalaBot::setParts(Head &head)
{
    this->_head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms temp = this->_arms;

    this->_arms = arms;
    arms = temp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs temp = this->_legs;

    this->_legs = legs;
    legs = temp;
}

void KoalaBot::swapParts(Head &head)
{
    Head temp = this->_head;

    this->_head = head;
    head = temp;
}

void KoalaBot::informations () const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctional() == true &&
        _legs.isFunctional() == true &&
        _head.isFunctional() == true) {
            return (true);
    }
    return (false);
}