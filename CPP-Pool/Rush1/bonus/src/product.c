/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 04
*/

#include <stdarg.h>
#include <stdio.h>
#include "new.h"
#include "product.h"

typedef struct
{
    Class   base;
    char *name;
    size_t count;
    size_t priority;
}   ProductClass;

static void Product_ctor(ProductClass *this, va_list *args)
{
    if (!this)
        raise("Class isn't initialised");
    if (!args)
        raise("No Args");
    this->name = strdup(va_arg(*args, char *));
    this->count = va_arg(*args, size_t);
    this->priority = va_arg(*args, size_t);
}

static void Product_dtor(Object *this)
{
    ProductClass *new = (ProductClass *) this;

    this = new;
    if (!this)
        raise("Class isn't initialised");
}

char *Product_to_str(Object *this)
{
    int count = 0;
    char *str = NULL;

    if (!this)
        raise("Value is uninitialized");
    if (this) {
        ProductClass *pr = (ProductClass *) this;
        str = malloc(sizeof(char) * (16 + 24 + strlen(pr->name)));
        if (!str)
            raise("Out of memory");
        sprintf(str, "<Product (%s, %zu, %zu)>", pr->name, pr->count, pr->priority);
    }
    return ((char *) str);
}

Object *Product_add(const Object *first, const Object *second)
{
    ProductClass *int1 = (ProductClass *)first;
    ProductClass *int2 = (ProductClass *)second;

    if (strcmp(int1->name, int2->name) != 0) raise("Can't add different products");
    return (new(Product, int1->name, int2->count + int1->count, int1->priority));
}

Object *Product_sub(const Object *first, const Object *second)
{
    ProductClass *int1 = (ProductClass *)first;
    ProductClass *int2 = (ProductClass *)second;

    if (strcmp(int1->name, int2->name) != 0) raise("Can't sub different products");
    return (new(Product, int1->name, int2->count - int1->count, int1->priority));
}

Object *Product_mul(const Object *first, const Object *second)
{
    raise("Can't multiply products");
}

Object *Product_div(const Object *first, const Object *second)
{
    raise("Can't divide products");
}

bool Product_eq(const Object *first, const Object *second)
{
    ProductClass *int1 = (ProductClass *)first;
    ProductClass *int2 = (ProductClass *)second;

    return (strcmp(int1->name, int2->name) == 0);
}

bool Product_lt(const Object *first, const Object *second)
{
    raise("Can't compare products");
}

bool Product_gt(const Object *first, const Object *second)
{
    raise("Can't compare products");
}

void *Product_get(const Object *product)
{
    return ((ProductClass *)product)->name;
}

static const ProductClass _description = {
    {   /* Class struct */
        .__size__ = sizeof(ProductClass),
        .__name__ = "Product",
        .__ctor__ = (ctor_t)&Product_ctor,
        .__dtor__ = (dtor_t)&Product_dtor,
        .__str__ = (to_string_t)&Product_to_str,
        .__add__ = (binary_operator_t)&Product_add,
        .__sub__ = (binary_operator_t)&Product_sub,
        .__mul__ = (binary_operator_t)&Product_mul,
        .__div__ = (binary_operator_t)&Product_div,
        .__eq__ = (binary_comparator_t)&Product_eq,
        .__gt__ = (binary_comparator_t)&Product_gt,
        .__lt__ = (binary_comparator_t)&Product_lt,
        .__get__= (get_t)&Product_get,
    },
    .name = NULL,
    .count = 0,
    .priority = 0
};

const Class *Product = (const Class *) &_description;