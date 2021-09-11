/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "point.h"

typedef struct
{
    Class   base;
    int     x, y;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
}

static void Point_dtor(Object *this)
{
    PointClass *new = (PointClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

Object *Point_add(const Object *first, const Object *second)
{
    PointClass *point1 = (PointClass *)first;
    PointClass *point2 = (PointClass *)second;

    return (new(Point, point1->x + point2->x,
        point1->y + point2->y));
}

Object *Point_sub(const Object *first, const Object *second)
{
    PointClass *point1 = (PointClass *)first;
    PointClass *point2 = (PointClass *)second;

    return (new(Point, point1->x - point2->x,
        point1->y - point2->y));
}

char *Point_to_str(Object *this)
{
    char *str = NULL;
    PointClass *that = (PointClass *) this;

    if (!this)
        raise("Class isn't initialised");
    str = malloc(sizeof(char) * (24 + 13));
    if (!str)
        raise("Out of memory");
    sprintf(str, "<Point (%d, %d)>", that->x, that->y);
    return (str);
}



static const PointClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = &Point_to_str,
        .__add__ = &Point_add,
        .__sub__ = &Point_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0
};

const Class *Point = (const Class *)&_description;
