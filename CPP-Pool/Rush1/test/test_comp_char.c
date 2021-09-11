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

Test(new, lt_char)
{
    Object  *point = new(Char, 40);
    Object  *point2 = new(Char, 41);

    cr_assert_eq(lt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, gt_char)
{
    Object  *point = new(Char, 42);
    Object  *point2 = new(Char, 41);

    cr_assert_eq(gt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, eq_char)
{
    Object  *point = new(Char, 41);
    Object  *point2 = new(Char, 41);

    cr_assert_eq(eq(point, point2), 1);
    delete(point2);
    delete(point);
}