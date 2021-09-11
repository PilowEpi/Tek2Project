/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#ifndef FRUIT_BOX_HPP_
#define FRUIT_BOX_HPP_

#include "Fruit.hpp"
#include "FruitNode.hpp"

class FruitBox
{
    public:
        FruitBox(int size);
        int nbFruits() const { return _size;};
        bool putFruit(Fruit *f);
        Fruit *pickFruit();
        FruitNode *head() const { return _head; };

        size_t getMaxSize() const { return _max_size;};
    private:
        FruitNode *_head;
        size_t _size;
        size_t _max_size;
};

#endif