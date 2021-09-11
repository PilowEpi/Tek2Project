/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4069_HPP_
#define C4069_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4069 : public nts::AComponent {
public:
    //Ctor Dtor
    C4069(const std::string &name);
    void simulate(size_t tick) override;
    //other methods are herited?
private:
};

#endif