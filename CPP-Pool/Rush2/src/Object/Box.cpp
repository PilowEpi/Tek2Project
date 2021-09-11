/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Wrap
*/


#include "Box.hpp"

Box::Box() :
    Wrap("Box")
{
}

bool Box::wrapMeThat(Object *obj)
{
    if (this->_open == true)
        return Wrap::wrapMeThat(obj);    
    return false;
}
