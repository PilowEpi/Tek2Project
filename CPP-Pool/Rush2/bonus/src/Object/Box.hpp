/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Box
*/

#ifndef BOX_HPP_
#define BOX_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include <SFML/Graphics.hpp>

class Box : public Wrap
{
public:
    Box();
    ~Box() {};
    bool wrapMeThat(Object *obj) override;
    sf::Sprite *sprite = carboard;
};

#endif
