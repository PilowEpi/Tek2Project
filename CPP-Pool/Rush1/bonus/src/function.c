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
    int (*exec) (Object *list, size_t, char **args);
}   FunctionClass;

static void Function_ctor(FunctionClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->exec = va_arg(*args, int (*)(Object *, size_t, char **));
}

static void Function_dtor(Object *this)
{
    FunctionClass *new = (FunctionClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

char *Function_to_str(Object *this)
{
    char *str = NULL;

    if (!this)
        raise("Value is uninitialized");
    if (this) {
        str = malloc(sizeof(char) * (30));
        if (!str)
            raise("Malloc Out of memory");
        sprintf(str, "<Function (%p)>", ((FunctionClass *) this)->exec);
    }
    return ((char *) str);
}

Object *Function_add(const Object *first, const Object *second)
{
    raise("Can't add functions");
}

Object *Function_sub(const Object *first, const Object *second)
{
    raise("Can't subtract functions");
}

Object *Function_mul(const Object *first, const Object *second)
{
    raise("Can't multiply functions");
}

Object *Function_div(const Object *first, const Object *second)
{
    raise("Can't divide functions");
}

bool Function_eq(const Object *first, const Object *second)
{
    raise("Can't compare functions");
}

bool Function_lt(const Object *first, const Object *second)
{
    raise("Can't compare functions");
}

bool Function_gt(const Object *first, const Object *second)
{
    raise("Can't compare functions'");
}

void *Function_get(const Object *obj)
{
    return ((FunctionClass *) obj)->exec;
}

static const FunctionClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(FunctionClass),
        .__name__ = "Function",
        .__ctor__ = (ctor_t)&Function_ctor,
        .__dtor__ = (dtor_t)&Function_dtor,
        .__str__ = (to_string_t)&Function_to_str,
        .__add__ = (binary_operator_t)&Function_add,
        .__sub__ = (binary_operator_t)&Function_sub,
        .__mul__ = (binary_operator_t)&Function_mul,
        .__div__ = (binary_operator_t)&Function_div,
        .__eq__ = (binary_comparator_t)&Function_eq,
        .__gt__ = (binary_comparator_t)&Function_gt,
        .__lt__ = (binary_comparator_t)&Function_lt,
        .__get__= (get_t)&Function_get,
    },
    .exec = NULL,
};

const Class *Function = (const Class *) &_description;