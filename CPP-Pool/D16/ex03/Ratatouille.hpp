/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/

#ifndef RATATOUILLE_HPP_
#define RATATOUILLE_HPP_

#include <iostream>
#include <sstream>
#include <string>

class Ratatouille
{
    public:
        Ratatouille();
        Ratatouille(Ratatouille const &other);
        ~Ratatouille();
        Ratatouille&operator=(const Ratatouille& other);

        Ratatouille &addVegetable(unsigned char);
        Ratatouille &addCondiment(unsigned int);
        Ratatouille &addSpice(double);
        Ratatouille &addSauce(const std::string &sauce);

        std::string kooc();
    private:
        std::ostringstream s;
};

#endif