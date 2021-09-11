/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#include "Woody.hpp"
#include "Toy.hpp"

Woody::Woody(const std::string &name, const std::string &ascii)
    : Toy(Toy::WOODY, name, ascii)
{
}

void Woody::speak(const std::string &statement)
{
    std::cout << "WOODY: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

Woody &operator<<(Woody &toy, const std::string &str) 
{
    toy.setStr(str);
    return toy;
}

std::ostream &operator<<(std::ostream &out, const Woody &toy)
{
    out << toy.getName() << std::endl << toy.getAscii() << std::endl;
}