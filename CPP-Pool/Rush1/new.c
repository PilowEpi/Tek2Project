/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 01
*/

#include <stdarg.h>
#include "new.h"
#include "player.h"

Object *new(const Class *class, ...)
{
    Class *new = NULL;
    va_list ap;

    if (class == NULL)
        raise("Class isn't initialised");
    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);
    return ((Object *)new);
}

Object *va_new(const Class *class, va_list* ap)
{
    Class *new = malloc(class->__size__);

    if (!new)
        raise("Malloc Out of memory");
    if (memcpy(new, class, (class->__size__)) == NULL)
        raise("Memcpy Out of memory");
    if (new->__ctor__)
        new->__ctor__((Object *) new, ap);
    return ((Object *) new);
}

void delete(Object *ptr)
{
    if (ptr) {
        if (((Class *) ptr)->__dtor__) {
            ((Class *) ptr)->__dtor__(ptr);
        }
        free(ptr);
    }
}