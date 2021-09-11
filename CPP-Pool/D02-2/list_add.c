/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex01
*/

#include <stdlib.h>
#include <stdio.h>

#include "generic_list.h"

bool list_add_elem_at_front(list_t *front_ptr, void *elem)
{
    node_t *new_node = malloc(sizeof(node_t));

    if (!new_node)
        return (false);
    new_node->value = elem;
    new_node->next = *front_ptr;
    *front_ptr = new_node;
    return (true);
}

bool list_add_elem_at_back(list_t *front_ptr, void *elem)
{
    node_t *new_node = malloc(sizeof(node_t));
    list_t head = *front_ptr;

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

bool list_add_elem_at_position(list_t *front_ptr, void *elem,
unsigned int position)
{
    node_t *new_node;
    list_t head = *front_ptr;

    if (!head || position == 0)
        return (list_add_elem_at_front(front_ptr, elem));
    if (position >= list_get_size(*front_ptr)) return (false);
    new_node = malloc(sizeof(node_t));
    if (!new_node) return (false);
    new_node->value = elem;
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    new_node->next = head->next;
    head->next = new_node;
    return (true);
}