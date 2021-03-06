/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef __ICHARACTER_HH__
# define __ICHARACTER_HH__

# include <string>

class AMateria;

class ICharacter
{
public:
    virtual ~ICharacter() {}
    virtual std::string const &getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;
};

#endif