/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** TrueComponent
*/

#ifndef TRUE_COMPONENT_HPP_
#define TRUE_COMPONENT_HPP_

#include "AComponent.hpp"
#include "APin.hpp"

class TrueComponent : public nts::AComponent
{
    public:
        TrueComponent(const std::string &name);
        void simulate(size_t tick);
    private:
};

#endif