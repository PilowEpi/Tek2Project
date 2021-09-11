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

Test(new, new_and_delete_float)
{
    Object  *point = new(Float, 12.232323f);
    char *value = str(point);

    cr_assert_str_eq(value, "<Float (12.232323)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_fail_float)
{
    Object  *point = new(Float, 12.232323f);
    char *value = str(point);

    cr_assert_str_neq(value, "<Float (13.232323)>");
    free(value);
    delete(point);
}