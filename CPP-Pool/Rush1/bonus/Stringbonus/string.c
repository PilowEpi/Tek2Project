/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "string.h"

typedef struct
{
    Class base;
    char *text;
}   StringClass;

static void String_ctor(StringClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->text = va_arg(*args, char *);
}

static void String_dtor(Object *this)
{
    StringClass *new = (StringClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

Object *String_add(const Object *first, const Object *second)
{
    StringClass *string1 = (StringClass *)first;
    StringClass *string2 = (StringClass *)second;

    return (new(String, strcat(string1->text, string2->text)));
}

bool String_eq(const Object *first, const Object *second)
{
    StringClass *string1 = (StringClass *)first;
    StringClass *string2 = (StringClass *)second;

    return (strcmp(string1->text, string2->text) == 0 ? 0 : 1);
}

bool String_lt(const Object *first, const Object *second)
{
    StringClass *string1 = (StringClass *)first;
    StringClass *string2 = (StringClass *)second;

    if (strlen(string1->text) < strlen(string2->text))
        return (0);
    else
        return (1);
}

bool String_gt(const Object *first, const Object *second)
{
    StringClass *string1 = (StringClass *)first;
    StringClass *string2 = (StringClass *)second;

    if (strlen(string1->text) > strlen(string2->text))
        return (0);
    else
        return (1);
}

static const StringClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(StringClass),
        .__name__ = "String",
        .__ctor__ = (ctor_t)&String_ctor,
        .__dtor__ = (dtor_t)&String_dtor,
        .__add__ = (binary_operator_t)&String_add,
        .__eq__ = (binary_comparator_t)&String_eq,
        .__gt__ = (binary_comparator_t)&String_gt,
        .__lt__ = (binary_comparator_t)&String_lt
    },
    .text = 0
};

const Class *String = (const Class *) &_description;