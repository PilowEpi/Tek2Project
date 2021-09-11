/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef C4040_HPP_
#define C4040_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4040 : public nts::AComponent {
public:
    //Ctor Dtor
    C4040(const std::string &name);
    void simulate(size_t tick);
    //other methods are herited?
private:
    void addOneBinary();
    void setAllValues();

    int _counter;
    int _binary[12] = {0};
};

#endif