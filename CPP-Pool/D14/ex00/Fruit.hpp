/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#ifndef FRUIT_HPP_
#define FRUIT_HPP_

#include <string>

class Fruit
{
    public:
        std::string getName() const { return _name; };
        int getVitamins() const { return _vitamins; };

        std::string _name;
        int _vitamins;
    protected:
        Fruit(std::string name, int vit) : _name(name), _vitamins(vit) {};
};

#endif