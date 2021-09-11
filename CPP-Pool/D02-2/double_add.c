/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex00
*/

#include <stdlib.h>
#include <stdio.h>

#include "double_list.h"

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new_node = malloc(sizeof(doublelist_node_t));
    double_list_t head = *front_ptr;

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = 0;
    if (!head) {
        *front_ptr = new_node;
        return (true);
    }
    while (head->next) {
        head = head->next;
    }
    head->next = new_node;
    return (true);
}

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *new_node;
    double_list_t head = *front_ptr;

    if (!head || position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    if (position >= double_list_get_size(*front_ptr)) return (false);
    new_node = malloc(sizeof(doublelist_node_t));
    if (!new_node) return (false);
    new_node->value = elem;
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    new_node->next = head->next;
    head->next = new_node;
    return (true);
}