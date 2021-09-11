/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** LittlePony
*/

#ifndef LITTLEPONY_HPP_
#define LITTLEPONY_HPP_

#include "Toy.hpp"
#include <SFML/Graphics.hpp>

class LittlePony : public Toy 
{
    public:
        LittlePony(const std::string &name = "Rainbow Dash");
        ~LittlePony();

        virtual void isTaken() const override;

        friend std::ostream &operator<<(std::ostream &os, const LittlePony &toy);
        sf::Sprite *sprite = 0;

};

#endif /* !LITTLEPONY_HPP_ */
