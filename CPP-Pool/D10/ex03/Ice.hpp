/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef CURE_HPP_
#define CURE_HPP_

#include "AMateria.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(const Ice& other);
        ~Ice();

        AMateria *clone() const final;
        void use(ICharacter &taget) final;
    private:
};

#endif