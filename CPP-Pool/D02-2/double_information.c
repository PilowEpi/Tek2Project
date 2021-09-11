/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex00
*/

#include <stddef.h>
#include <stdio.h>

#include "double_list.h"

unsigned int double_list_get_size(double_list_t list)
{
    double_list_t *index = &list;
    int size = 0;

    if (!list)
        return (0);
    while ((*index)) {
        size++;
        (*index) = (*index)->next;
    }
    return (size);
}

bool double_list_is_empty(double_list_t list)
{
    if (!list)
        return (true);
    return (false);
}

void double_list_dump(double_list_t list)
{
    double_list_t *index = &list;

    if (!list) {
        return;
    }
    while ((*index)->next) {
        printf("%f\n", (*index)->value);
        (*index) = (*index)->next;
    }
    printf("%f\n", (*index)->value);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    double_list_t *index = &list;

    while ((*index)) {
        if ((*index)->value == value)
            return (*index);
        (*index) = (*index)->next;
    }
    return (0);
}