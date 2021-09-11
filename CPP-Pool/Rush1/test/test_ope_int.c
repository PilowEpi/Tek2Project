/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "int.h"

Test(new, add_int)
{
    Object  *point = new(Int, 41);
    Object  *point2 = new(Int, 41);
    char *value = str(addition(point, point2));

    cr_assert_str_eq(value, "<Int (82)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, sub_int)
{
    Object  *point = new(Int, 41);
    Object  *point2 = new(Int, 41);
    char *value = str(subtraction(point, point2));

    cr_assert_str_eq(value, "<Int (0)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, mul_int)
{
    Object  *point = new(Int, 2);
    Object  *point2 = new(Int, 41);
    char *value = str(multiplication(point, point2));

    cr_assert_str_eq(value, "<Int (82)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, div_int)
{
    Object  *point = new(Int, 41);
    Object  *point2 = new(Int, 41);
    char *value = str(division(point, point2));

    cr_assert_str_eq(value, "<Int (1)>");
    free(value);
    delete(point2);
    delete(point);
}
