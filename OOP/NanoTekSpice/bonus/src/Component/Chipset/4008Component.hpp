/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4008_HPP_
#define C4008_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4008 : public nts::AComponent {
public:
    //Ctor Dtor
    C4008(const std::string &name);
    void simulate(size_t tick) override;
    //other methods are herited?
private:
};

#endif