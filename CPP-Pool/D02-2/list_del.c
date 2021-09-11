/*
** EPITECH PROJECT, 2020
** cpp_d02a
** File description:
** ex01
*/

#include <stdlib.h>
#include "generic_list.h"

bool list_del_elem_at_front(list_t *front_ptr)
{
    list_t head = *front_ptr;

    if (!(*front_ptr)) return (false);
    *front_ptr = head->next;
    free(head);
    return (true);
}

bool list_del_elem_at_back(list_t *front_ptr)
{
    list_t head = *front_ptr;
    node_t *cpy = 0;

    if (!(*front_ptr)) return (false);
    while (head->next->next)
        head = head->next;
    cpy = head->next;
    head->next = 0;
    free(cpy);
    return (true);
}

bool list_del_elem_at_position(list_t *front_ptr,
unsigned int position)
{
    list_t head = *front_ptr;
    node_t *cpy = 0;

    if (!head || position == 0)
        return (list_del_elem_at_front(front_ptr));
    if (position >= list_get_size(*front_ptr)) return (false);
    for (unsigned int i = 0; i < position - 1; i++)
        head = head->next;
    cpy = head->next;
    head->next = head->next->next;
    free(cpy);
    return (true);
}

void list_clear(list_t *front_ptr)
{
    list_t head = *front_ptr;
    list_t copy = 0;

    if (!head) return;
    while (head){
        copy = head;
        head = head->next;
        free(copy);
    }
    *front_ptr = 0;
}