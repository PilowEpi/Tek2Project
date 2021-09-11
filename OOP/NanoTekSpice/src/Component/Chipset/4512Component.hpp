/*
** EPITECH PROJECT, 2021
** 4512Component.hpp 
** File description:
** nano
*/

#ifndef C4512_HPP_
#define C4512_HPP_

#include "AComponent.hpp"
#include "LogicGate.hpp"

class C4512 : public nts::AComponent {
public:
    //Ctor Dtor
    C4512(const std::string &name);
    void simulate(size_t tick) override;
    //other methods are herited?
private:
};

#endif