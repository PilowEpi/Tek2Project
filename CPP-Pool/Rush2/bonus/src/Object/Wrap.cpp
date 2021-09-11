/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Wrap
*/

#include "Wrap.hpp"

Wrap::Wrap(const std::string &name, Object::Type type) :
    Object(name, type)
{
    _obj = nullptr;
}

Wrap::~Wrap()
{
    if (_obj)
        delete _obj;
}

bool Wrap::wrapMeThat(Object *obj)
{
    std::cout << "tuuuut tuuut tuut" << std::endl;
    this->_open = false;
    if (!this->_obj) {
        this->_obj = obj;
        return true;
    } else {
        return false; 
    }
}

bool Wrap::isOpen() const
{
    return (this->_open);
}

void Wrap::openMe()
{
    this->_open = true; 
}

void Wrap::closeMe()
{
    this->_open = false; 
}

void Wrap::isTaken() const
{
    std::cout << "whistles while working" << std::endl;
}

Object *Wrap::whatsInside() const
{
    return (this->_obj);
}