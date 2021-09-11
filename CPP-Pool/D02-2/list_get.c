/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex01
*/

#include "generic_list.h"

void *list_get_elem_at_front(list_t list)
{
    list_t *index = &list;

    if (!list) {
        return ((void *) 0);
    }
    return ((*index)->value);
}

void *list_get_elem_at_back(list_t list)
{
    list_t *index = &list;

    if (!list)
        return ((void *) 0);

    while ((*index)->next)
        (*index) = (*index)->next;
    return ((*index)->value);
}

void *list_get_elem_at_position(list_t list,
unsigned int position)
{
    list_t *index = &list;

    if (!list || position == 0)
        return (list_get_elem_at_front(list));
    if (position >= list_get_size(list))
        return (false);
    for (unsigned int i = 0; i < position - 1; i++)
        (*index) = (*index)->next;
    return ((*index)->next->value);
}