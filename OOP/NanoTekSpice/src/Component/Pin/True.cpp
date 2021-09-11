/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** TrueComponent
*/

#include "True.hpp"

TrueComponent::TrueComponent(const std::string &name)
    :AComponent(name, "true", 1)
{
    this->_pins[0] = new nts::APin(nts::OUT, nts::TRUE);
}

void TrueComponent::simulate(size_t tick)
{
    nts::AComponent *c;

    tick = tick;
    if (this->_links.size() == 0 || this->_links[0].second == NULL)
        throw PinError("True simulate: invalid link\n");
    c = static_cast<nts::AComponent *>(this->_links[0].second);
    c->setPinValue(this->_links[0].first, this->_pins[0]->getPinValue());
    this->_isCompute = true;
}