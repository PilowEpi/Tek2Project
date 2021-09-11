/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** APin
*/

#include "APin.hpp"

nts::APin::APin(const nts::PinType type, const nts::Tristate value)
    : _value(value), _type(type)
{
}

void nts::APin::setPinValue(const nts::Tristate value)
{
    if (this->_type == nts::OTHER)
        throw PinError("setPinValue: try to set the value of an bad type pin\n");
    this->_value = value;
}