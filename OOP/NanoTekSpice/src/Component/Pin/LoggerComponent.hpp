/*
** EPITECH PROJECT, 2021
** Nanotekspice
** File description:
** Nanotekspice
*/

#ifndef CLOGGER_HPP_
#define CLOGGER_HPP_

#include <iostream>
#include <fstream>
#include <string>

#include "AComponent.hpp"
#include "LogicGate.hpp"

class CLogger : public nts::AComponent {
public:
    //Ctor Dtor
    CLogger(const std::string &name);
    void simulate(size_t tick) override;
    //other methods are herited?
private:
};

#endif