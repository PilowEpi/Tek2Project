/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "AMateria.hpp"
#include "Ice.hpp"

Ice::Ice()
    :AMateria("ice")
{
}

Ice::Ice(const Ice &other)
    :AMateria(other)
{
}

Ice::~Ice()
{
}

AMateria *Ice::clone() const
{
    return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
    std::cout << "* shoots and ice bolt at " << target.getName() << " *" << std::endl;
}