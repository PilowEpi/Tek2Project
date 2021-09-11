/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4017_HPP_
#define C4017_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4017 : public nts::AComponent {
public:
    //Ctor Dtor
    C4017(const std::string &name);
    void simulate(size_t tick);
    //other methods are herited?
    size_t getIndexOfQ();
private:
};

#endif