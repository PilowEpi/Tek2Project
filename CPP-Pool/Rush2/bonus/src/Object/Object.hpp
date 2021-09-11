/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Object
*/

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <ostream>
#include <iostream>
#include <SFML/Graphics.hpp>

extern sf::Sprite *carboard;
extern sf::Sprite *carboardClose;
extern sf::Sprite *elf;
extern sf::Sprite *littlepony;
extern sf::Sprite *teddy;

class Object
{
public:
    enum Type {
        TOY,
        WRAP
    };
    Object(const std::string &name, Type type);
    virtual ~Object() {};

    // Getter
    virtual void isTaken() const;
    virtual bool isOpen() const;
    const std::string &getName() const {return _name;};
    Type getType() const {return _type;};
    virtual Object *whatsInside() const;
    virtual const std::string &getToyType() const;

    // Action
    virtual void openMe();
    virtual void closeMe();
    virtual bool wrapMeThat(Object *obj);
    friend std::ostream &operator<<(std::ostream &os, const Object &obj);
    virtual std::string &serialize(std::string &xml, int depth);
	int x = 1920/1.5;
	int y = 1080/2;
	int dx = 1920/1.5;
	int dy = 1080/2;
	int sizeX = 40;
	int sizeY = 40;
    std::string _name;
    Type _type;
    sf::Sprite *sprite = 0;
protected:
};

#endif
