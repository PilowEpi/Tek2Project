/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy
{
    public:
        explicit Buzz(const std::string &name, const std::string &ascii = "buzz.txt");
    private:
};

#endif