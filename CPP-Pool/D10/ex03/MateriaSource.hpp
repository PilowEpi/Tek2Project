/*
** EPITECH PROJECT, 2020
** CPOOL D10
** File description:
** CPOOL D10
*/

#ifndef MATERIA_SOURCE_HPP_
#define MATERIA_SOURCE_HPP_

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource();
        ~MateriaSource();

        void learnMateria(AMateria *materia) final;
        AMateria *createMateria(const std::string &type) final;
    private:
        AMateria *_memory[4];
        AMateria *_lastCopied;
};

#endif