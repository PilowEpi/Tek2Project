/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex00
*/

#include <stdlib.h>
#include "double_list.h"

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t head = *front_ptr;

    if (!(*front_ptr)) return (false);
    *front_ptr = head->next;
    free(head);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t head = *front_ptr;
    doublelist_node_t *cpy = 0;

    if (!(*front_ptr)) return (false);
    while (head->next->next)
        head = head->next;
    cpy = head->next;
    head->next = 0;
    free(cpy);
    return (true);
}

bool double_list_del_elem_at_position(double_list_t *front_ptr,
unsigned int position)
{
    double_list_t head = *front_ptr;
    doublelist_node_t *cpy = 0;

    if (!head || position == 0)
        return (double_list_del_elem_at_front(front_ptr));
    if (position >= double_list_get_size(*front_ptr)) return (false);
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    cpy = head->next;
    head->next = head->next->next;
    free(cpy);
    return (true);
}