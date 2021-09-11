/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "float.h"

Test(new, add_float)
{
    Object  *point = new(Float, 41.2f);
    Object  *point2 = new(Float, 41.2f);
    char *value = str(addition(point, point2));

    cr_assert_str_eq(value, "<Float (82.400002)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, sub_float)
{
    Object  *point = new(Float, 41.2f);
    Object  *point2 = new(Float, 41.2f);
    char *value = str(subtraction(point, point2));

    cr_assert_str_eq(value, "<Float (0.000000)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, mul_float)
{
    Object  *point = new(Float, 2.0f);
    Object  *point2 = new(Float, 41.0f);
    char *value = str(multiplication(point, point2));

    cr_assert_str_eq(value, "<Float (82.000000)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, div_float)
{
    Object  *point = new(Float, 41.0);
    Object  *point2 = new(Float, 41.0);
    char *value = str(division(point, point2));

    cr_assert_str_eq(value, "<Float (1.000000)>");
    free(value);
    delete(point2);
    delete(point);
}
