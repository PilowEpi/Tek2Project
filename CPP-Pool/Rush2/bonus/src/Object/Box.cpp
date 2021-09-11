/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Wrap
*/


#include "Box.hpp"

extern sf::Sprite *carboard;

Box::Box() :
    Wrap("Box")
{
    this->sprite = carboard;
}

bool Box::wrapMeThat(Object *obj)
{
    if (this->_open == true)
        return Wrap::wrapMeThat(obj);    
    return false;
}
