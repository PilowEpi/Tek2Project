/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include <SFML/Graphics.hpp>
#include "Object.hpp"

class Toy : public Object
{
    public:
        Toy(const std::string &name = "404 The game !", const std::string &t = "Toy");
        ~Toy();

        virtual const std::string &getToyType() const override;

        friend std::ostream &operator<<(std::ostream &os, const Toy &toy);

        std::string _type;
        sf::Sprite *sprite = 0;

    protected:
};

#endif /* !TOY_HPP_ */
