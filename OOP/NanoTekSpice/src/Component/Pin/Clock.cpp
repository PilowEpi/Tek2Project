/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** ClockComponent
*/

#include "Clock.hpp"

ClockComponent::ClockComponent(const std::string &name)
    :AComponent(name, "clock", 1)
{
    this->_pins[0] = new nts::APin(nts::OUT);
    this->_init = 0;
}

void ClockComponent::simulate(size_t tick)
{
    nts::AComponent *c = static_cast<nts::AComponent *>(this->_links[0].second);

    tick = tick;
    if (this->_links.size() == 0 || this->_links[0].second == NULL)
        throw PinError("Clock simulate: invalid link\n");

    if (this->_isCompute == true)
        return;
    if (this->_init == 1) {
        c->setLast(this->_pins[0]->getPinValue());
        if (this->_pins[0]->getPinValue() == nts::TRUE)
            this->setPinValue(0, nts::FALSE);
        else if (this->_pins[0]->getPinValue() == nts::FALSE)
            this->setPinValue(0, nts::TRUE);
    }
    this->_init = 1;
    c->setPinValue(this->_links[0].first, this->_pins[0]->getPinValue());
    this->_isCompute = true;
}