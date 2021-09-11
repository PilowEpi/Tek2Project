/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Teddy
*/

#include "Teddy.hpp"

Teddy::Teddy(const std::string &name) : Toy(name, "Teddy")
{
}

Teddy::~Teddy()
{
}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Teddy &toy)
{
    os << toy.getName() << ", a Toy of type Teddy, overall an Object. Is taken!" << std::endl;
    return (os);
}