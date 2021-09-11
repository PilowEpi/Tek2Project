/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4071_HPP_
#define C4071_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4071 : public nts::AComponent {
public:
    //Ctor Dtor
    C4071(const std::string &name);
    void simulate(size_t tick);
    //other methods are herited?
private:
};

#endif