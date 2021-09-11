/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** OutputComponent
*/

#include "Output.hpp"
#include "Error.hpp"


OutputComponent::OutputComponent(const std::string &name)
    :AComponent(name, "output", 1)
{
    this->_pins[0] = new nts::APin(nts::IN);
}

void OutputComponent::simulate(size_t tick)
{
    size_t pins[] = {0};
    tick = tick;
    if (this->_links.size() == 0 || this->_links[0].second == NULL)
        throw PinError("Output simulate: invalid link\n");
    this->simulateBack(0);
    this->_isCompute = true;
}