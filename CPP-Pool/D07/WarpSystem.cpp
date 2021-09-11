/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>

#include "WarpSystem.hpp"

// QuantumReactor

WarpSystem::QuantumReactor::QuantumReactor(void)
{
    this->_stability = true;
}

bool WarpSystem::QuantumReactor::isStable(void)
{
    return (this->_stability);
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

// Core

WarpSystem::Core::Core(WarpSystem::QuantumReactor *reactor)
{
    this->_coreReactor = reactor;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor(void)
{
    return (this->_coreReactor);
}