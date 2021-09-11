/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "float.h"

typedef struct
{
    Class   base;
    float c;
}   FloatClass;

static void Float_ctor(FloatClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->c = va_arg(*args, double);
}

static void Float_dtor(Object *this)
{
    FloatClass *new = (FloatClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

Object *Float_to_str(Object *this)
{
    char *str = NULL;
    FloatClass *that = (FloatClass *) this;

    if (!this)
        raise("Class isn't initialised");
    str = malloc(sizeof(char) * (10 + 22));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Float (%f)>", that->c);
    return (str);
}

Object *Float_add(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (new(Float, float1->c + float2->c));
}

Object *Float_sub(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (new(Float, float1->c - float2->c));
}

Object *Float_mul(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (new(Float, float1->c * float2->c));
}

Object *Float_div(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    if (float2->c == 0)
        raise("Cannot divide by 0");
    return (new(Float, float1->c / float2->c));
}

bool Float_eq(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (float1->c == float2->c);
}

bool Float_lt(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (float1->c < float2->c);
}

bool Float_gt(const Object *first, const Object *second)
{
    FloatClass *float1 = (FloatClass *)first;
    FloatClass *float2 = (FloatClass *)second;

    return (float1->c > float2->c);
}

static const FloatClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FloatClass),
        .__name__ = "Float",
        .__ctor__ = (ctor_t)&Float_ctor,
        .__dtor__ = (dtor_t)&Float_dtor,
        .__str__ = (to_string_t)&Float_to_str,
        .__add__ = (binary_operator_t)&Float_add,
        .__sub__ = (binary_operator_t)&Float_sub,
        .__mul__ = (binary_operator_t)&Float_mul,
        .__div__ =(binary_operator_t) &Float_div,
        .__eq__ = (binary_comparator_t)&Float_eq,
        .__gt__ = (binary_comparator_t)&Float_gt,
        .__lt__ = (binary_comparator_t)&Float_lt
    },
    .c = 0
};

const Class *Float = (const Class *) &_description;
