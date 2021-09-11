/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#ifndef FRUIT_NODE_HPP_
#define FRUIT_NODE_HPP_

#include "Fruit.hpp"

class FruitNode
{
    public:
        FruitNode(Fruit *fruit, FruitNode *n, FruitNode *p) : fruit(fruit), next(n), prev(p) {};
        Fruit *fruit;
        FruitNode *next;
        FruitNode *prev;
    private:
};

#endif