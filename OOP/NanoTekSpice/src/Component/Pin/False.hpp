/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** FalseComponent
*/

#ifndef FALSE_COMPONENT_HPP_
#define FALSE_COMPONENT_HPP_

#include "AComponent.hpp"
#include "APin.hpp"

class FalseComponent : public nts::AComponent
{
    public:
        FalseComponent(const std::string &name);
        void simulate(size_t tick);
    private:
};

#endif