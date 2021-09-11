/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 02
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "vertex.h"

typedef struct
{
    Class base;
    int x;
    int y;
    int z;
}   VertexClass;

static void Vextex_ctor(VertexClass *this, va_list *args)
{
    if (!this)
        raise("Vextex_ctor:Class isn't initialised");
    if (!args)
        raise("Vextex_ctor:No Args");
    this->x = va_arg(*args, int);
    this->y = va_arg(*args, int);
    this->z = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    VertexClass *new = (VertexClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

char *Vertex_to_str(Object *this)
{
    VertexClass *that = (VertexClass *) this;
    char *str = NULL;

    if (!this)
        raise("Class isn't initialised");
    str = malloc(sizeof(char) * (16 + 36));
    if (!str)
        raise("Malloc Out of memory");
    sprintf(str, "<Vertex (%d, %d, %d)>", that->x, that->y, that->z);
    return (str);
}

Object *Vertex_add(const Object *ob1, const Object *ob2)
{
    VertexClass *vertex1 = (VertexClass *)ob1;
    VertexClass *vertex2 = (VertexClass *)ob2;

    return (new(Vertex, vertex1->x + vertex2->x,
        vertex1->y + vertex2->y, vertex1->z + vertex2->z));
}

Object *Vertex_sub(const Object *ob1, const Object *ob2)
{
    VertexClass *vertex1 = (VertexClass *)ob1;
    VertexClass *vertex2 = (VertexClass *)ob2;

    return (new(Vertex, vertex1->x - vertex2->x,
        vertex1->y - vertex2->y, vertex1->z - vertex2->z));
}

static const VertexClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vextex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = &Vertex_to_str,
        .__add__ = &Vertex_add,
        .__sub__ = &Vertex_sub,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .x = 0,
    .y = 0,
    .z = 0,
};

const Class *Vertex = (const Class *)&_description;