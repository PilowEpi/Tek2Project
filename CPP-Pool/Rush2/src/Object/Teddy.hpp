/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Teddy
*/

#ifndef TEDDY_HPP_
#define TEDDY_HPP_

#include "Toy.hpp"

class Teddy : public Toy 
{
    public:
        Teddy(const std::string &name = "Bear");
        ~Teddy();

        virtual void isTaken() const override;

        friend std::ostream &operator<<(std::ostream &os, const Teddy &toy);
};

#endif /* !TEDDY_HPP_ */