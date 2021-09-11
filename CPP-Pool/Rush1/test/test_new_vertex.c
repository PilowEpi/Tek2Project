/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "vertex.h"

Test(new, new_and_delete_vertex)
{
    Object  *vertex = new(Vertex, 41, -42, 0);
    char *value = str(vertex);

    cr_assert_str_eq(value, "<Vertex (41, -42, 0)>");
    free(value);
    delete(vertex);
}

Test(new, new_and_delete_fail_vertex)
{
    Object  *vertex = new(Vertex, 41, -42, 0);
    char *value = str(vertex);

    cr_assert_str_neq(value, "<Vertex (40, -42, 0)>");
    free(value);
    delete(vertex);
}

Test(new, new_and_delete_high_number_vertex)
{
    Object  *vertex = new(Vertex, 2000000, -2000000, 0);
    char *value = str(vertex);

    cr_assert_str_eq(value, "<Vertex (2000000, -2000000, 0)>");
    free(value);
    delete(vertex);
}