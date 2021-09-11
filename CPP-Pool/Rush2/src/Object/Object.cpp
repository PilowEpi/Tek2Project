/*
** EPITECH PROJECT, 2020
** rush 2
** File description:
** object
*/

#include "Object.hpp"

void Object::isTaken() const
{
    std::cerr << "isTaken not define" << std::endl;
    throw;
}

bool Object::isOpen() const
{
    std::cerr << "isOpen not define" << std::endl;
    throw;
    return false;
}


Object::Object(const std::string &name, Object::Type type) :
    _name(name),
    _type(type)
{
}

const std::string &Object::getName() const
{
    return (this->_name);
}

void Object::openMe()
{
    std::cerr << "openMe not define" << std::endl;
    throw;
}

void Object::closeMe()
{
    std::cerr << "closeMe not define" << std::endl;
    throw;
}

bool Object::wrapMeThat(Object *obj)
{
    (void)obj;
    std::cerr << "wrapMeThat not define" << std::endl;
    throw;
    return false;
}

std::ostream &operator<<(std::ostream &os, const Object &obj)
{
    os << obj.getName() << ", an object. Is taken!" << std::endl;
    return (os);
}

Object *Object::whatsInside() const
{
    std::cerr << "whatsInside not define" << std::endl;
    throw;   
}

const std::string &Object::getToyType() const
{
    std::cerr << "getTType not define" << std::endl;
    throw;
}

std::string &Object::serialize(std::string &xml, int depth)
{
    if (this->getType() == Object::WRAP) {
        xml += std::string("<") + this->getName() + std::string(">\n");
        if (this->whatsInside())
            this->whatsInside()->serialize(xml, depth + 1);
        xml += std::string("</") + this->getName() + std::string(">\n");
    } else {
        xml += std::string("<") + this->getToyType() + std::string(">\n");
        xml += this->getName() + std::string("\n");
        xml += std::string("</") + this->getToyType() + std::string(">\n");
    }
    return (xml);
}