/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4013_HPP_
#define C4013_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4013 : public nts::AComponent {
public:
    //Ctor Dtor
    C4013(const std::string &name);
    void simulate(size_t tick);
private:
};

#endif