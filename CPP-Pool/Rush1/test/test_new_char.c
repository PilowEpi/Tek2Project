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

Test(new, new_and_delete_char)
{
    Object  *point = new(Char, 'a');
    char *value = str(point);

    cr_assert_str_eq(value, "<Char (a)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_fail_char)
{
    Object  *point = new(Char, 'a');
    char *value = str(point);

    cr_assert_str_neq(value, "<Char (b)>");
    free(value);
    delete(point);
}