/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#include "LittleHand.hpp"
#include "Lemon.hpp"
#include "Lime.hpp"
#include "Banana.hpp"

void LittleHand::sortFruitBox(FruitBox &unsorted,
                        FruitBox &lemons,
                        FruitBox &bananas,
                        FruitBox &limes)
{
    size_t u_size = unsorted.nbFruits();
    Fruit *tmp = 0;

    for (size_t i = 0; i < u_size; i++) {
        tmp = unsorted.pickFruit();

        if (!tmp)
            break;
        if (dynamic_cast<Lime *>(tmp)) {
            if (limes.putFruit(tmp) == false)
                unsorted.putFruit(tmp);
        }
        else if (dynamic_cast<Lemon *>(tmp)) {
            if (lemons.putFruit(tmp) == false)
                unsorted.putFruit(tmp);
        }
        else if (dynamic_cast<Banana *>(tmp)) {
            if (bananas.putFruit(tmp) == false)
                unsorted.putFruit(tmp);
        }
        else if (dynamic_cast<Fruit *>(tmp)) {
            unsorted.putFruit(tmp);
        }
    }
}