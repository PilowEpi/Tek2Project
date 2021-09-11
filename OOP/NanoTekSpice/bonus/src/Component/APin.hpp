/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** APin
*/

#ifndef APIN_HPP_
#define APIN_HPP_

#include "IComponent.hpp"
#include "Error.hpp"

namespace nts
{
    class APin
    {
        public:
            APin(const nts::PinType type, const nts::Tristate value=nts::UNDEFINED);

            void setPinValue(nts::Tristate value);

            nts::Tristate getPinValue() const { return _value;};
            nts::PinType getPinType() const { return _type;};

        private:
            nts::Tristate _value;
            nts::PinType _type;
    };
};

#endif