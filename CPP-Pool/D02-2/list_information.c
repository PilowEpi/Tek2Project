/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex01
*/

#include <stddef.h>
#include <stdio.h>

#include "generic_list.h"

unsigned int list_get_size(list_t list)
{
    list_t *index = &list;
    int size = 0;

    if (!list)
        return (0);
    while ((*index)) {
        size++;
        (*index) = (*index)->next;
    }
    return (size);
}

bool list_is_empty(list_t list)
{
    if (!list)
        return (true);
    return (false);
}

void list_dump(list_t list, value_displayer_t val_disp)
{
    list_t *index = &list;

    if (!list) {
        return;
    }
    while ((*index)->next) {
        val_disp((*index)->value);
        (*index) = (*index)->next;
    }
    val_disp((*index)->value);
}

node_t *list_get_first_node_with_value(list_t list,
void *value, value_comparator_t val_comp)
{
    list_t *index = &list;

    while ((*index)) {
        if (val_comp((*index)->value, value) == 0)
            return (*index);
        (*index) = (*index)->next;
    }
    return (0);
}