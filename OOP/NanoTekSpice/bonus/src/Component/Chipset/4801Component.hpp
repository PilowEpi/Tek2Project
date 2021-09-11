/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4081_HPP_
#define C4081_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"


class C4801 : public nts::AComponent {
public:
    //Ctor Dtor
    C4801(const std::string &name);
    void simulate(size_t tick) {};
    //other methods are herited?
private:
};

#endif