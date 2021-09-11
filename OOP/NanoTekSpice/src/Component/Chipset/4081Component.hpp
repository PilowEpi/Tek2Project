/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef COMPO_4081_HPP_
#define COMPO_4081_HPP_

#include "AComponent.hpp"

class C4081 : public nts::AComponent {
public:
    //Ctor Dtor
    C4081(const std::string &name);
    void simulate(size_t tick);
private:
};

#endif