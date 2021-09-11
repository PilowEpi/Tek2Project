/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4094_HPP_
#define C4094_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"


class C4094 : public nts::AComponent {
public:
    //Ctor Dtor
    C4094(const std::string &name);
    void simulate(size_t tick) {};
    //other methods are herited?
private:
};
#endif