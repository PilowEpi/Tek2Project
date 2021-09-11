/*
** EPITECH PROJECT, 2020
** CPOOL D13
** File description:
** CPOOL D13
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy
{
    public:
        explicit Woody(const std::string &name, const std::string &ascii = "woody.txt");

        void speak(const std::string &statement) final;
    private:
};

#endif