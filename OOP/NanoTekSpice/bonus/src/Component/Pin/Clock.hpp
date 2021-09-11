/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** ClockComponent
*/

#ifndef CLOCK_COMPONENT_HPP_
#define CLOCK_COMPONENT_HPP_

#include "AComponent.hpp"
#include "APin.hpp"

class ClockComponent : public nts::AComponent
{
    public:
        ClockComponent(const std::string &name);
        void simulate(size_t tick);
};

#endif