/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/


#ifndef C4001_HPP_
#define C4001_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4001 : public nts::AComponent {
public:
    //Ctor Dtor
    C4001(const std::string &name);
    void simulate(size_t tick);
    //other methods are herited?
private:
};

#endif