/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#include <iostream>
#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure()
    :AMateria("cure")
{
}

Cure::Cure(const Cure &other)
    :AMateria(other)
{
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
    return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
    std::cout << "* heals "<< target.getName() <<"'s wounds *" << std::endl;
}