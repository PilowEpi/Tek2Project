/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 05
*/

#ifndef CONTAINER_H
# define CONTAINER_H

# include "object.h"
# include "iterator.h"
# include "raise.h"

typedef struct Container_s Container;

typedef Iterator *(*iter_t)(Container *this);
typedef size_t (*len_t)(Container *this);
typedef Object *(*getitem_t)(Container *this, ...);
typedef void (*setitem_t)(Container *this, ...);
typedef void (*resize_t)(Container *this, size_t l,...);
typedef void (*pushback_t)(Container *this, ...);
typedef void (*popback_t)(Container *this);
typedef void (*popat_t)(Container *this, size_t p);

struct Container_s {
    Class       base;
    resize_t      __resize__;
    len_t       __len__;
    iter_t      __begin__;
    iter_t      __end__;
    getitem_t   __getitem__;
    setitem_t   __setitem__;
    pushback_t __pushback__;
    popback_t __popback__;
    popat_t __popat__;
};

# define len(c)             ((Container *)c)->__len__(c)
# define begin(c)           ((Container *)c)->__begin__(c)
# define end(c)             ((Container *)c)->__end__(c)
# define getitem(c, ...)    ((Container *)c)->__getitem__(c, __VA_ARGS__)
# define setitem(c, ...)    ((Container *)c)->__setitem__(c, __VA_ARGS__)
# define resize(c, l, ...)	((Container *)c)->__resize__(c, l,__VA_ARGS__)
# define push_back(c, ...) 	((Container *)c)->__pushback__(c, __VA_ARGS__)
# define pop_back(c) 	((Container *)c)->__popback__(c)
# define pop_at(c, p) 	((Container *)c)->__popat__(c, p)



#endif
