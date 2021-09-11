/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#ifndef LITTLE_HAND_HPP_
#define LITTLE_HAND_HPP_

#include "FruitBox.hpp"
#include "Fruit.hpp"

class LittleHand
{
    public:
        static void sortFruitBox(FruitBox &unsorted,
                        FruitBox &lemons,
                        FruitBox &bananas,
                        FruitBox &limes);
};

#endif