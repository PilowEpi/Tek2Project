/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#include "DomesticKoala.hpp"
#include "KoalaAction.hpp"

DomesticKoala::DomesticKoala(KoalaAction &action)
{
    this->action = action;
    this->vec.reserve(256);
}

DomesticKoala::~DomesticKoala()
{
    this->vec.clear();
}

DomesticKoala::DomesticKoala(const DomesticKoala &other)
{
    this->action = other.action;
    this->vec = other.vec;
}

DomesticKoala &DomesticKoala::operator=(const DomesticKoala &other)
{
    this->action = other.action;
    this->vec = other.vec;

    return (*this);
}

void DomesticKoala::learnAction(unsigned char command, methodPointer_t action)
{
    if (vec[command])
        return;
    vec[command] = action;
}

void DomesticKoala::doAction(unsigned char command, const std::string &parameter)
{
    if (!vec[command])
        return;
    (action.*vec[command])(parameter);
}

void DomesticKoala::unlearnAction(unsigned char command)
{
    if (!vec[command])
        return;
    vec[command] = 0;
}

void DomesticKoala::setKoalaAction(KoalaAction &action)
{
    this->action = action;
}