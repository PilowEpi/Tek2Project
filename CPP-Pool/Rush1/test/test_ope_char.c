/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "new.h"
#include "char.h"

Test(new, add_char)
{
    Object  *point = new(Char, 'a');
    Object  *point2 = new(Char, 1);
    char *value = str(addition(point, point2));

    cr_assert_str_eq(value, "<Char (b)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, sub_char)
{
    Object  *point = new(Char, 'b');
    Object  *point2 = new(Char, 1);
    char *value = str(subtraction(point, point2));

    cr_assert_str_eq(value, "<Char (a)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, mul_char)
{
    Object  *point = new(Char, 11);
    Object  *point2 = new(Char, 6);
    char *value = str(multiplication(point, point2));

    cr_assert_str_eq(value, "<Char (B)>");
    free(value);
    delete(point2);
    delete(point);
}

Test(new, div_char)
{
    Object  *point = new(Char, '0');
    Object  *point2 = new(Char, 1);
    char *value = str(division(point, point2));

    cr_assert_str_eq(value, "<Char (0)>");
    free(value);
    delete(point2);
    delete(point);
}
