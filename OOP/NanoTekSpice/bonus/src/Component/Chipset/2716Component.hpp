/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C2716_HPP_
#define C2716_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"


class C2716 : public nts::AComponent {
public:
    //Ctor Dtor
    C2716(const std::string &name);
    void simulate(size_t tick) {};
    //other methods are herited?
private:
};

#endif