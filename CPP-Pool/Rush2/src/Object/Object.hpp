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

class Object
{
    public:
        enum Type {
            TOY,
            WRAP
        };
        Object(const std::string &name, Type type);
        virtual ~Object() {};

        virtual void isTaken() const;
        virtual bool isOpen() const;
        const std::string &getName() const;
        Type getType() const {return this->_type;}
        virtual Object *whatsInside() const;
        virtual const std::string &getToyType() const;

        virtual void openMe();
        virtual void closeMe();
        virtual bool wrapMeThat(Object *obj);
        friend std::ostream &operator<<(std::ostream &os, const Object &obj);
        virtual std::string &serialize(std::string &xml, int depth);
    protected:
        std::string _name;
        Type _type;
};

#endif