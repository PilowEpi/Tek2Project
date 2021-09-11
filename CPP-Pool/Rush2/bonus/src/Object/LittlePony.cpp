/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** LittlePony
*/

#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &name) : Toy(name, "LittlePony")
{
    this->sprite = littlepony;
}

LittlePony::~LittlePony()
{
}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}

std::ostream &operator<<(std::ostream &os, const LittlePony &toy)
{
    os << toy.getName() << ", a Toy of type LittlePony, overall an Object. Is taken!" << std::endl;
    return (os);
}
