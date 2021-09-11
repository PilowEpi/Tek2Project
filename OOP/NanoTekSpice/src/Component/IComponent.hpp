/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** IComponent
*/

#ifndef I_COMPONENT_HPP_
#define I_COMPONENT_HPP_

#include <iostream>
#include <string>

namespace nts
{
    enum Tristate {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false
    };

    enum PinType {
        IN,
        OUT,
        OTHER
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual void    simulate(std::size_t tick) = 0;
            virtual nts::Tristate   compute(std::size_t pin) = 0;
            virtual void    setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void    dump() = 0;
    };
    
}

#endif