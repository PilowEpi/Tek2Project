/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "point.h"

Test(new, point_ope_add)
{
    Object  *point = new(Point, 41, -42);
    Object  *point2 = new(Point, 2, 2);
    char *value = str(addition(point, point2));

    cr_assert_str_eq(value, "<Point (43, -40)>");
    free(value);
    delete(point);
    delete(point2);
}

Test(new, point_ope_sub)
{
    Object  *point = new(Point, 41, -42);
    Object  *point2 = new(Point, 2, 2);
    char *value = str(subtraction(point, point2));

    cr_assert_str_eq(value, "<Point (39, -44)>");
    free(value);
    delete(point);
    delete(point2);
}