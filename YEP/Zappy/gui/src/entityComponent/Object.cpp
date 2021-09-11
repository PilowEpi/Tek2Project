/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Object
*/

#include <ostream>
#include "Object.hpp"

AObject::~AObject()
{
};

rl::Vec3 AObject::boudingBoxCenter()
{
    return ((rl::Vec3)_boundingBox._bd.min + (rl::Vec3)_boundingBox._bd.max)/2;
}