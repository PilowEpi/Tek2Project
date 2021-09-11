/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4514_HPP_
#define C4514_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4514 : public nts::AComponent {
public:
    //Ctor Dtor
    C4514(const std::string &name);
    void simulate(size_t tick) override;
    void reset_decode();
    //other methods are herited?
private:
};

#endif