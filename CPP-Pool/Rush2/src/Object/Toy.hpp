/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Object.hpp"

class Toy : public Object
{
    public:
        Toy(const std::string &name = "404 The game !", const std::string &t = "Toy");
        ~Toy();

        virtual const std::string &getToyType() const override;

        friend std::ostream &operator<<(std::ostream &os, const Toy &toy);

    protected:
        std::string _ttype;
};

#endif /* !TOY_HPP_ */
