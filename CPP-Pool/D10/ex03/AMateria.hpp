/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef AMATERIA_HPP_
#define AMATERIA_HPP_

#include <string>
#include "ICharacter.hpp"

class AMateria
{
    public:
        AMateria(const std::string& type);
        AMateria(const AMateria &other);
        virtual ~AMateria();

        const std::string &getType() const;
        unsigned int getXP() const;

        virtual AMateria *clone() const = 0;
        virtual void use(ICharacter &target);

        AMateria &operator=(const AMateria &other);
    private:
        std::string _type;
        unsigned int _xp;
};

#endif