/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy(const std::string &name, const std::string &t) : 
    Object(name, Object::TOY),
    _type(t)
{
}

Toy::~Toy()
{
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    os << toy.getName() << ", a toy, overall an Object. Is taken!" << std::endl;
    return (os);
}

const std::string &Toy::getToyType() const
{
    return (this->_type);
}