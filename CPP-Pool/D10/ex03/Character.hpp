/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(const std::string &name);
        Character(const Character &other);
        ~Character();

        std::string const &getName() const final;
        void equip(AMateria *m) final;
        void unequip(int idx) final;
        void use(int idx, ICharacter &target) final;

        Character &operator=(const Character &other);
    private:
        AMateria *_inventory[4];
        size_t _size;
        std::string _name;
};

#endif