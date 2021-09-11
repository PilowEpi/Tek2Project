/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** GitfPaper
*/

#ifndef GIFTPAPER_HPP_
#define GIFTPAPER_HPP_

#include "Object.hpp"
#include "Wrap.hpp"
#include <SFML/Graphics.hpp>

class GiftPaper : public Wrap
{
public:
    GiftPaper();
    ~GiftPaper() {};
    sf::Sprite *sprite = 0;
};

#endif /* GIFTPAPER_HPP_ */
