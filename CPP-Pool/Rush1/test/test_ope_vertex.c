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

Test(new, vertex_ope_add)
{
    Object  *point = new(Vertex, 41, -42, 0);
    Object  *point2 = new(Vertex, 2, 2, 0);
    char *value = str(addition(point, point2));

    cr_assert_str_eq(value, "<Vertex (43, -40, 0)>");
    free(value);
    delete(point);
    delete(point2);
}

Test(new, vertex_ope_sub)
{
    Object  *point = new(Vertex, 41, -42, 0);
    Object  *point2 = new(Vertex, 2, 2, 0);
    char *value = str(subtraction(point, point2));

    cr_assert_str_eq(value, "<Vertex (39, -44, 0)>");
    free(value);
    delete(point);
    delete(point2);
}