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

Test(new, new_and_delete_point)
{
    Object  *point = new(Point, 41, -42);
    char *value = str(point);

    cr_assert_str_eq(value, "<Point (41, -42)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_fail_point)
{
    Object  *point = new(Point, 41, -42);
    char *value = str(point);

    cr_assert_str_neq(value, "<Point (40, -42)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_high_number_point)
{
    Object  *point = new(Point, 2000000, -2000000);
    char *value = str(point);

    cr_assert_str_eq(value, "<Point (2000000, -2000000)>");
    free(value);
    delete(point);
}