/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#include "Toy.hpp"
#include "Picture.hpp"

Toy::Toy(ToyType type, const std::string &name, const std::string &file)
    : Picture(file)
{
    this->_type = type;
    this->_name = name;
}

bool Toy::setAscii(std::string const &filename)
{
    return (this->getPictureFromFile(filename));
}