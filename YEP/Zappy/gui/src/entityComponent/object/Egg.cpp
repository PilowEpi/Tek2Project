/*
** EPITECH PROJECT, 2020
** YEP Zappy
** File description:
** Egg
*/

#include "../Object.hpp"
#include "../../Zappy.hpp"

Egg::Egg(rl::Vec2 coord, std::shared_ptr<rl::Texture> egg, rl::Color color, int id)
{
    _coords = rl::Vec2(coord);
    _egg = egg;
    _color = color;
    _size = rl::Vec3(0.4f, 0.6f, 0.4f);
    _destroyed = false;
    _id = id;
}

void Egg::render(rl::Camera3d *cam)
{
    if (_destroyed)
        return;
    _egg->drawTexture(rl::Vec3(_coords.y * 1.6, 0.9, _coords.x * 1.6), _size, _color);
}

void Egg::simulate()
{

}

void Egg::handleEvent(std::string event)
{

}