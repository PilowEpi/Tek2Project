/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <iostream>
#include <string>

#include "DroidMemory.hpp"

DroidMemory::DroidMemory()
{
    this->_fingerPrint = random() % 10000000;
    this->_exp = 0;
}

// Setter

void DroidMemory::setExp(size_t exp)
{
    this->_exp = exp;
}

void DroidMemory::setFingerPrint(size_t fingerprint)
{
    this->_fingerPrint = fingerprint;
}

// Getter

size_t DroidMemory::getExp() const
{
    return (this->_exp);
}

size_t DroidMemory::getFingerPrint() const
{
    return (this->_fingerPrint);
}

// Operator

DroidMemory &operator>>(DroidMemory &mem1, DroidMemory &mem2)
{
    size_t xorVar = mem1.getFingerPrint() ^ mem2.getFingerPrint();
    mem2.setExp(mem2.getExp() + mem1.getExp());
    mem2.setFingerPrint(xorVar);
    return (mem1);
}

DroidMemory &operator<<(DroidMemory &mem1, const DroidMemory &mem2)
{
    size_t xorVar =  mem2.getFingerPrint() ^ mem1.getFingerPrint();
    mem1.setExp(mem2.getExp() + mem1.getExp());
    mem1.setFingerPrint(xorVar);
    return (mem1);
}

DroidMemory &operator+=(DroidMemory &mem1, const size_t exp)
{
    mem1.setExp(mem1.getExp() + exp);
    return (mem1);
}

DroidMemory &operator+=(DroidMemory &mem1, const DroidMemory &mem2)
{
    mem1.setExp(mem1.getExp() + mem2.getExp());
    return (mem1);
}

DroidMemory &operator+(DroidMemory &mem1, const size_t exp)
{
    DroidMemory *mem2 = new DroidMemory;

    mem2->setExp(mem1.getExp() + exp);
    return (*mem2);
}

DroidMemory &operator+(DroidMemory &mem1, DroidMemory &mem2)
{
    DroidMemory *new_mem = new DroidMemory;

    new_mem->setExp(mem1.getExp() + mem2.getExp());
    return (*new_mem);
}


std::ostream &operator<<(std::ostream &out, const DroidMemory &mem)
{
    out << "DroidMemory '" << mem.getFingerPrint() << "', " << mem.getExp();
    return out;
}