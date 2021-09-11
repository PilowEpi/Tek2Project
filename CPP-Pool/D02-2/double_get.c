/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex00
*/

#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    double_list_t *index = &list;

    if (!list) {
        return ((double) 0);
    }
    return ((*index)->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t *index = &list;

    if (!list)
        return ((double) 0);

    while ((*index)->next)
        (*index) = (*index)->next;
    return ((*index)->value);
}

double double_list_get_elem_at_position(double_list_t list,
unsigned int position)
{
    double_list_t *index = &list;

    if (!list || position == 0)
        return (double_list_get_elem_at_front(list));
    if (position >= double_list_get_size(list))
        return (false);
    for (unsigned int i = 0; i < position - 1; i++)
        (*index) = (*index)->next;
    return ((*index)->next->value);
}