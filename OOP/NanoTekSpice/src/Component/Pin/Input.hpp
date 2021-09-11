/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** InputComponent
*/


#ifndef INPUT_COMPONENT_HPP_
#define INPUT_COMPONENT_HPP_

#include "AComponent.hpp"
#include "APin.hpp"

class InputComponent : public nts::AComponent
{
    public:
        InputComponent(const std::string &name);
        void simulate(size_t tick);
    private:
};

#endif