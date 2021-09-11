/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** FalseComponent
*/

#include "False.hpp"

FalseComponent::FalseComponent(const std::string &name)
    :AComponent(name, "false", 1)
{
    this->_pins[0] = new nts::APin(nts::OUT, nts::FALSE);
}

void FalseComponent::simulate(size_t tick)
{
    nts::AComponent *c;

    tick = tick;
    if (this->_links.size() == 0 || this->_links[0].second == NULL)
        throw PinError("False simulate: invalid link\n");
    c = static_cast<nts::AComponent *>(this->_links[0].second);
    c->setPinValue(this->_links[0].first, this->_pins[0]->getPinValue());
    this->_isCompute = true;
}