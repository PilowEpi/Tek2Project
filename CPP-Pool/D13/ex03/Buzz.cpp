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