/*
** EPITECH PROJECT, 2019
** cpp_rush1
** File description:
** Exercice 06
*/

#include <stdlib.h>
#include <stdarg.h>
#include "container.h"
#include "raise.h"
#include "list.h"
#include "new.h"

typedef struct SListClass ListClass;

typedef struct SListClass {
    Container base;
    Class *_type;
    size_t size;
    Object *_obj;
    ListClass *next;
} ListClass;

typedef struct {
    Iterator base;
    ListClass* _list;
    ListClass* _cur;
} ListIteratorClass;

static int is_before(ListIteratorClass *first, ListIteratorClass *second)
{
    if (!first || !second) raise("Classes aren't initialised");
    if (!first->_cur || !second->_cur) return 0;
    ListClass *list = first->_cur;
    while (list) {
        list = list->next;
        if (list == second->_cur) return 1;
    }
    return 0;
}

static void     ListIterator_ctor(ListIteratorClass *this, va_list *args)
{
    this->_list = va_arg(*args, ListClass *);
    this->_cur = va_arg(*args, ListClass *);
}

static bool     ListIterator_eq(ListIteratorClass *this, ListIteratorClass *other)
{
    return (this->_cur == other->_cur);
}

static bool     ListIterator_gt(ListIteratorClass *this, ListIteratorClass *other)
{
    return !is_before(this, other);
}

static bool     ListIterator_lt(ListIteratorClass *this, ListIteratorClass *other)
{
    return is_before(this, other);    
}

static void     ListIterator_incr(ListIteratorClass *this)
{
    this->_cur = this->_cur->next;
}

static Object   *ListIterator_getval(ListIteratorClass *this)
{
    if (this->_cur == NULL)
        raise("Out of range");
    return this->_cur->_obj;
}

static ListClass *ListIterator_getvalbefore(ListIteratorClass *this)
{
    ListClass *tmp = this->_list;

    while (tmp) {
        if (tmp->next == this->_cur)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}

static void ListIterator_setval(ListIteratorClass *this, ...)
{
    va_list va;
    ListClass *before = ListIterator_getvalbefore(this);
    if (!this)
        raise("Class isn't initialised");
    if (!before)
        raise("Linked list is corrupted");
    va_start(va, this);
    delete(this->_cur->_obj);
    this->_cur->_obj = va_new((Class *) this->_cur->_type, &va);
    va_end(va);
}

static const ListIteratorClass   ListIteratorDescr = {
    {   /* Iterator struct */
        {   /* Class struct */
            .__size__ = sizeof(ListIteratorClass),
            .__name__ = "ListIterator",
            .__ctor__ = (ctor_t)&ListIterator_ctor,
            .__dtor__ = NULL,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = (binary_comparator_t)&ListIterator_eq,
            .__gt__ = (binary_comparator_t)&ListIterator_gt,
            .__lt__ = (binary_comparator_t)&ListIterator_lt,
        },
        .__incr__ = (incr_t)&ListIterator_incr,
        .__getval__ = (getval_t)&ListIterator_getval,
        .__setval__ = (setval_t)&ListIterator_setval,
    },
    ._list = NULL,
    ._cur = NULL
};

static const Class    *ListIterator = (const Class *)&ListIteratorDescr;

static void List_add_back(ListClass *this, Object *new)
{
    ListClass *newelem = malloc(sizeof(ListClass));

    if (newelem == NULL) raise("Out of memory");
    newelem->_obj = new;
    newelem->next = NULL;
    newelem->size = 0;
    newelem->_type = this->_type;
    this->size++;
    while (this && this->next) {
        this = this->next;
    }
    this->next = newelem;
}

static void List_pushback(ListClass *this, ...)
{
    va_list va;

    va_start(va, this);
    Object *new = va_new(this->_type, &va);
    List_add_back(this, new);
    va_end(va);
}

static void List_del_back(ListClass *this)
{
    if (!this) raise("Class isn't initialised'");

    this->size--;
    this = this->next;
    while (this->next && this->next->next) {
        this = this->next;
    }
    if (this && this->next && this->next->_obj) {
        delete(this->next->_obj);
    }
    if (!this->next) {
        delete(this->_obj);
        free(this);
    } else {
        free(this->next);
        this->next = NULL;
    }
}

static void List_del_pointer(ListClass *this, ListClass *obj)
{
    ListClass *ls = this;

    while (ls != NULL) {
        if (ls->next == obj) {
            ls->next = ls->next->next;
            this->size--;
            return;
        }
        ls = ls->next;
    }
}

static void List_popat(ListClass *this, size_t index)
{
    ListClass *tmp = this->next;
    for (size_t i = 0; i < this->size; i++) {
        if (i == index) {
            List_del_pointer(this, tmp);
        }
        tmp = tmp->next;
    }
}

static void List_ctor(ListClass *this, va_list *args)
{
    va_list copy;
    size_t size = 0;

    if (!this) raise("Class isn't initialised");
    size = va_arg(*args, size_t);
    this->_type = va_arg(*args, Class *);
    this->size = 0;
    for (size_t i = 0; i < size; i++) {
        va_copy(copy, *args);
        List_add_back(this, va_new(this->_type, &copy));
        va_end(copy);
    }
}

static void List_dtor(Object *this)
{
    if (!this) raise("Class isn't initialised");
    for (size_t i = 0; i < ((ListClass *) this)->size; i++) {
        List_del_back(this);
    }
}

static Iterator *List_begin(ListClass *this)
{
    return (new(ListIterator, this, this->next));
}

static Iterator *List_end(ListClass *list)
{
    while (list && list->next) {
        list = list->next;
    }
    return (new(ListIterator, list, list));
}

static size_t List_len(ListClass *this)
{
    if (!this) raise("Class isn't initialised");
    return this->size;
}

static Object *List_getitem(ListClass *this, ...)
{
    ListClass *list = this->next;
    size_t wanted_index = 0;
    size_t index = 0;
    va_list ap;

    if (!this)
        raise("Value is uninitialized");
    va_start(ap, this);
    wanted_index = va_arg(ap, size_t);
    va_end(ap);
    if (wanted_index >= this->size) raise("Index out of range");
    while (index < wanted_index) list = list->next;
    return (list->_obj);
}

static void List_setitem(ListClass *this, ...)
{
    size_t pos = 0;
    ListClass *list = this;
    va_list ap;

    if (!this)
        raise("Value is uninitialized");
    va_start(ap, this);
    pos = va_arg(ap, size_t);
    if (pos > this->size)
        raise("Out of range");
    list = list->next;
    for (size_t i = 0;list && i < pos; i++) {
        list = list->next;
    }
    ((Class *) list->_type)->__ctor__(list->_obj, &ap);
    va_end(ap);
}

static const ListClass   _descr = {
    {   /* Container struct */
        {   /* Class struct */
            .__size__ = sizeof(ListClass),
            .__name__ = "List",
            .__ctor__ = (ctor_t)&List_ctor,
            .__dtor__ = (dtor_t)&List_dtor,
            .__str__ = NULL,
            .__add__ = NULL,
            .__sub__ = NULL,
            .__mul__ = NULL,
            .__div__ = NULL,
            .__eq__ = NULL,
            .__gt__ = NULL,
            .__lt__ = NULL,
        },
        .__len__ = (len_t)&List_len,
        .__begin__ = (iter_t)&List_begin,
        .__end__ = (iter_t)&List_end,
        .__getitem__ = (getitem_t)&List_getitem,
        .__setitem__ = (setitem_t)&List_setitem,
        .__pushback__ = (pushback_t)&List_pushback,
        .__popback__ = (popback_t)&List_del_back,
        .__popat__ = (popat_t)&List_popat,
    },
    ._type = NULL,
    ._obj = NULL,
    .next = NULL
};

const Class *List = (const Class *)&_descr;