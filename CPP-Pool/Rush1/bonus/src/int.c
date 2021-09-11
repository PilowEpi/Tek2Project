/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "int.h"

typedef struct
{
    Class   base;
    int c;
}   IntClass;

static void Int_ctor(IntClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->c = va_arg(*args, int);
}

static void Int_dtor(Object *this)
{
    IntClass *new = (IntClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

char *Int_to_str(Object *this)
{
    int nb = 0;
    int count = 0;
    char *str = NULL;

    if (!this)
        raise("Value is uninitialized");
    nb = ((IntClass *) this)->c;
    for (; nb != 0; count++)
        nb /= 10;
    if (this) {
        str = malloc(sizeof(char) * (10 + count));
        if (!str)
            raise("Malloc Out of memory");
        sprintf(str, "<Int (%d)>", ((IntClass *) this)->c);
    }
    return ((char *) str);
}

Object *Int_add(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (new(Int, int1->c + int2->c));
}

Object *Int_sub(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (new(Int, int1->c - int2->c));
}

Object *Int_mul(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (new(Int, int1->c * int2->c));
}

Object *Int_div(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    if (int2->c == 0)
        raise("Cannot divide by 0");
    return (new(Int, int1->c / int2->c));
}

bool Int_eq(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (int1->c == int2->c);
}

bool Int_lt(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (int1->c < int2->c);
}

bool Int_gt(const Object *first, const Object *second)
{
    IntClass *int1 = (IntClass *)first;
    IntClass *int2 = (IntClass *)second;

    return (int1->c > int2->c);
}

static const IntClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(IntClass),
        .__name__ = "Int",
        .__ctor__ = (ctor_t)&Int_ctor,
        .__dtor__ = (dtor_t)&Int_dtor,
        .__str__ = (to_string_t)&Int_to_str,
        .__add__ = (binary_operator_t)&Int_add,
        .__sub__ = (binary_operator_t)&Int_sub,
        .__mul__ = (binary_operator_t)&Int_mul,
        .__div__ = (binary_operator_t)&Int_div,
        .__eq__ = (binary_comparator_t)&Int_eq,
        .__gt__ = (binary_comparator_t)&Int_gt,
        .__lt__ = (binary_comparator_t)&Int_lt
    },
    .c = 0
};

const Class *Int = (const Class *) &_description;