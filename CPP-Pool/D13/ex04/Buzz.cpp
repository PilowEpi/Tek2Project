/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#include "Buzz.hpp"
#include "Toy.hpp"

Buzz::Buzz(const std::string &name, const std::string &ascii)
    : Toy(Toy::BUZZ, name, ascii)
{
}

void Buzz::speak(const std::string &statement)
{
    std::cout << "BUZZ: " << this->getName() << " \"" << statement << "\"" << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Buzz &toy)
{
    out << toy.getName() << std::endl << toy.getAscii() << std::endl;
}

Buzz &operator<<(Buzz &toy, const std::string &str) 
{
    toy.setStr(str);
    return toy;
}