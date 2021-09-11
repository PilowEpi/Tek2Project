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

Test(new, new_and_delete_int)
{
    Object  *point = new(Int, 41);
    char *value = str(point);

    cr_assert_str_eq(value, "<Int (41)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_fail_int)
{
    Object  *point = new(Int, 41);
    char *value = str(point);

    cr_assert_str_neq(value, "<Int (40)>");
    free(value);
    delete(point);
}

Test(new, new_and_delete_high_int)
{
    Object  *point = new(Int, 2000000);
    char *value = str(point);

    cr_assert_str_eq(value, "<Int (2000000)>");
    free(value);
    delete(point);
}