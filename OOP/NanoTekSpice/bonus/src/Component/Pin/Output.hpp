/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** OutputComponent
*/


#ifndef OUTPUT_COMPONENT_HPP_
#define OUTPUT_COMPONENT_HPP_

#include "AComponent.hpp"
#include "APin.hpp"

class OutputComponent : public nts::AComponent
{
    public:
        OutputComponent(const std::string &name);
        void simulate(size_t tick);
    private:
};

#endif