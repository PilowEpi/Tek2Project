/*
** EPITECH PROJECT, 2020
** CPOOL D14
** File description:
** CPOOL D14
*/

#include "FruitBox.hpp"
#include "FruitNode.hpp"
#include <iostream>

FruitBox::FruitBox(int size)
{
    this->_max_size = size;
    this->_head = 0;
    this->_size = 0;
}

bool checkFruit(Fruit *f, FruitNode *head)
{
    FruitNode *tmp = head;

    while (tmp) {
        if (tmp->fruit == f) {
            return (true);
        }
        tmp = tmp->next;
    }
    return (false);
}

bool FruitBox::putFruit(Fruit *fruit)
{
    FruitNode *new_node = 0;
    FruitNode *tmp = this->_head;

    if (this->_size == this->_max_size || checkFruit(fruit, this->_head) == true)
        return (false);
    if (!this->_head) {
        this->_size++;
        this->_head = new FruitNode(fruit, 0, 0);
        return (true);
    }
    while (tmp->next)
        tmp = tmp->next;
    new_node = new FruitNode(fruit, 0, tmp);
    tmp->next = new_node;
    this->_size++;
    return (true);
}

Fruit *FruitBox::pickFruit()
{
    Fruit *fruit = 0;
    FruitNode *tmp = this->_head;

    if (!this->_head)
        return 0;
    fruit = this->_head->fruit;
    this->_head = this->_head->next;
    delete tmp;
    this->_size--;
    return (fruit);
}