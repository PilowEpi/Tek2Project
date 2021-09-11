/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** InputComponent
*/

#ifndef AND_GATE_HPP_
#define AND_GATE_HPP_

#include "IComponent.hpp"
#include "Error.hpp"

namespace nts
{
    class LogicGate
    {
        public:
            LogicGate() {};
            ~LogicGate() {};

            static nts::Tristate ANDGate(nts::Tristate first, nts::Tristate second);
            static nts::Tristate ORGate(nts::Tristate first, nts::Tristate second);
            static nts::Tristate XORGate(nts::Tristate first, nts::Tristate second);
            static nts::Tristate NOTGate(nts::Tristate first, nts::Tristate second = UNDEFINED); // Can throw error !
            static nts::Tristate NANDGate(nts::Tristate first, nts::Tristate second);
            static nts::Tristate NORGate(nts::Tristate first, nts::Tristate second);
            static std::pair<nts::Tristate, nts::Tristate> flipFlop(nts::Tristate data[]);
    };
};

#endif