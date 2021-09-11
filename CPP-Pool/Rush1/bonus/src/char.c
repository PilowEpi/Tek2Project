/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "char.h"

typedef struct {
    Class base;
    char x;
} CharClass;

static void Char_ctor(CharClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    this->x = va_arg(*args, int);
}

static void Char_dtor(CharClass *this)
{
    if (!this)
        raise("Class isn't initialised");
}

static Object *Char_add(Object *first, Object *second)
{
    char x = 0;
    Object *result = NULL;

    if (!first || !second)
        raise("Value is uninitialized");
    x = ((CharClass *) first)->x + ((CharClass *) second)->x;
    result = new(Char, x);
    return (result);
}

static Object *Char_sub(Object *first, Object *second)
{
    char x = 0;
    Object *result = NULL;

    if (!first || !second)
        raise("Value is uninitialized");
    x = ((CharClass *) first)->x - ((CharClass *) second)->x;
    result = new(Char, x);
    return (result);
}

static Object *Char_mul(Object *first, Object *second)
{
    char x = 0;
    Object *result = NULL;

    if (!first || !second)
        raise("Value is uninitialized");
    x = ((CharClass *) first)->x * ((CharClass *) second)->x;
    result = new(Char, x);
    return (result);
}

static Object *Char_div(Object *first, Object *second)
{
    char x = 0;
    Object *result = NULL;

    if (!first || !second)
        raise("Value is uninitialized");
    x = ((CharClass *) first)->x / ((CharClass *) second)->x;
    result = new(Char, x);
    return (result);
}

static bool Char_eq(Object *first, Object *second)
{
    if (!first || !second)
        raise("Value is uninitialized");
    else if (((CharClass *) first)->x == ((CharClass *) second)->x)
        return (true);
    return (false);
}

static bool Char_gt(Object *first, Object *second)
{
    if (!first || !second)
        raise("Value is uninitialized");
    else if (((CharClass *) first)->x > ((CharClass *) second)->x)
        return (true);
    return (false);
}

static bool Char_lt(Object *first, Object *second)
{
    if (!first || !second)
        raise("Value is uninitialized");
    else if (((CharClass *) first)->x < ((CharClass *) second)->x)
        return (true);
    return (false);
}

char *Char_to_str(Object *this)
{
    char *str = NULL;

    if (!this)
        raise("Value is uninitialized");
    str = malloc(sizeof(char) * 11);
    if (!str)
        raise("Malloc Out of memory");
    sprintf(str, "<Char (%c)>", ((CharClass *) this)->x);
    return ((char *) str);
}

static const CharClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(CharClass),
        .__name__ = "Char",
        .__ctor__ = (ctor_t) &Char_ctor,
        .__dtor__ = (dtor_t) &Char_dtor,
        .__str__ = (to_string_t)&Char_to_str,
        .__add__ =  (binary_operator_t)&Char_add,
        .__sub__ =  (binary_operator_t)&Char_sub,
        .__mul__ = (binary_operator_t)&Char_mul,
        .__div__ = (binary_operator_t)&Char_div,
        .__eq__ = (binary_comparator_t)&Char_eq,
        .__gt__ = (binary_comparator_t)&Char_gt,
        .__lt__ = (binary_comparator_t)&Char_lt
    },
    .x = 0
};

const Class *Char = (const Class *) &_description;