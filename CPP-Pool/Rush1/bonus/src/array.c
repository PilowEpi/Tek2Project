/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 05
*/

#include <stdlib.h>
#include <stdarg.h>
#include "raise.h"
#include "array.h"
#include "new.h"

typedef struct
{
    Container   base;
    Class       *_type;
    size_t      _size;
    Object      **_tab;
}   ArrayClass;

typedef struct {
    Iterator    base;
    ArrayClass  *_array;
    size_t      _idx;
}   ArrayIteratorClass;

static void     ArrayIterator_ctor(ArrayIteratorClass *this, va_list *args)
{
    this->_array = va_arg(*args, ArrayClass *);
    this->_idx = va_arg(*args, int);
}

static bool     ArrayIterator_eq(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx == other->_idx);
}

static bool     ArrayIterator_gt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx > other->_idx);
}

static bool     ArrayIterator_lt(ArrayIteratorClass *this, ArrayIteratorClass *other)
{
    return (this->_idx < other->_idx);
}

static void     ArrayIterator_incr(ArrayIteratorClass *this)
{
    this->_idx += 1;
}

static Object   *ArrayIterator_getval(ArrayIteratorClass *this)
{
    if (this->_idx >= this->_array->_size)
        raise("Out of range");
    return (this->_array->_tab[this->_idx]);
}

static void     ArrayIterator_setval(ArrayIteratorClass *this, ...)
{
    va_list va;
    if (!this)
        raise("Class isn't initialised");
    Object *old = this->_array->_tab[this->_idx];
    va_start(va, this);
    this->_array->_tab[this->_idx] = va_new(this->_array->_tab[this->_idx], &va);
    va_end(va);
    delete(old);
}

static const ArrayIteratorClass   ArrayIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayIteratorClass),
            .__name__ = "ArrayIterator",
            .__ctor__ = (ctor_t)&ArrayIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ArrayIterator_eq,
            .__gt__ = (binary_comparator_t)&ArrayIterator_gt,
            .__lt__ = (binary_comparator_t)&ArrayIterator_lt,
        },
        .__incr__ = (incr_t)&ArrayIterator_incr,
        .__getval__ = (getval_t)&ArrayIterator_getval,
        .__setval__ = (setval_t)&ArrayIterator_setval,
    },
    ._array = NULL,
    ._idx = 0
};

static const Class    *ArrayIterator = (const Class *)&ArrayIteratorDescr;

static void Array_ctor(ArrayClass *this, va_list *args)
{
    va_list copy;

    if (!this)
        raise("Class isn't initialised");
    this->_size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->_tab = NULL;
    if (this->_size == 0)
        raise("Can't initialize Array with 0 size");
    this->_tab = malloc(sizeof(Object*) * this->_size);
    if (!this->_tab)
        raise("Malloc Out of memory");
    for (size_t i = 0; i < this->_size ; i++) {
        va_copy(copy, *args);
        this->_tab[i] = va_new(this->_type, &copy);
        va_end(copy);
    }
}

static void Array_dtor(ArrayClass *this)
{
    for (unsigned int i = 0; i < this->_size; i++)
        delete(this->_tab[i]);
    free(this->_tab);
}

static size_t   Array_len(ArrayClass *this)
{
    return (this->_size);
}

static Iterator *Array_begin(ArrayClass *this)
{
    return (new(ArrayIterator, this, 0));
}

static Iterator *Array_end(ArrayClass *this)
{
    return (new(ArrayIterator, this, this->_size - 1));
}

static Object *Array_getitem(ArrayClass *this, ...)
{
    int index = 0;
    va_list ap;

    if (!this)
        raise("Value is uninitialized");
    va_start(ap, this);
    index = va_arg(ap, int);
    va_end(ap);
    return (((Object *) this->_tab[index]));
}

static void Array_setitem(ArrayClass *this, ...)
{
    size_t pos = 0;
    va_list ap;

    if (!this || !this->_tab)
        raise("Value is uninitialized");
    va_start(ap, this);
    pos = va_arg(ap, size_t);
    if (pos > this->_size)
        raise("Out of range");
    ((Class *) this->_tab[pos])->__ctor__(this->_tab[pos], &ap);
    va_end(ap);
}

static void Array_resize(ArrayClass *this, size_t new_size, ...)
{
    va_list ap;
    va_list copy;
    size_t old_size = this->_size;

    if (old_size == new_size) return;
    if (old_size < new_size) {
        this->_size = new_size;
        va_start(ap, new_size);
        this->_tab = realloc(this->_tab, this->_size * sizeof(Object *));
        for (size_t i = old_size; i < this->_size; i++) {
            va_copy(copy, ap);
            this->_tab[i] = va_new(this->_type, &copy);
            va_end(copy);
        }
        va_end(ap);
    } else {
        for (size_t i = old_size - 1; i > new_size - 1; i--) {
            delete(this->_tab[i]);
        }
        this->_tab = realloc(this->_tab, this->_size * sizeof(Object *));
        this->_size = new_size;
    }
}

static const ArrayClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ArrayClass),
            .__name__ = "Array",
            .__ctor__ = (ctor_t)&Array_ctor,
            .__dtor__ = (dtor_t)&Array_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__resize__ = (resize_t)&Array_resize,
        .__len__ = (len_t)&Array_len,
        .__begin__ = (iter_t)&Array_begin,
        .__end__ = (iter_t)&Array_end,
        .__getitem__ = (getitem_t)&Array_getitem,
        .__setitem__ = (setitem_t)&Array_setitem,
    },
    ._type = NULL,
    ._size = 0,
    ._tab = NULL
};

const Class   *Array = (const Class *)&_descr;
