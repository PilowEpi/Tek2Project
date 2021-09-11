/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Wrap
*/



#ifndef WRAP_HPP_
#define WRAP_HPP_

#include "Object.hpp"

class Wrap : public Object
{
    public:
        Wrap(const std::string &name = "Wrap", Object::Type type = Object::WRAP);
        //Wrap(const Wrap &other);
        virtual ~Wrap();

        Object *whatsInside() const override;
        void isTaken() const;
        bool isOpen() const override;

        void openMe();
        void closeMe();
        bool wrapMeThat(Object *obj) override;

        Object *_obj = 0;
        bool _open = true;

    protected:
};

#endif
