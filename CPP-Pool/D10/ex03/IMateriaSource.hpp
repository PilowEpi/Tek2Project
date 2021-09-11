/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef __IMATERIASOURCE_HH__
# define __IMATERIASOURCE_HH__

# include "AMateria.hpp"

class IMateriaSource
{
public:
    virtual ~IMateriaSource() {}
    virtual AMateria * createMateria(std::string const & type) = 0;
    virtual void learnMateria(AMateria *) = 0;
};

#endif