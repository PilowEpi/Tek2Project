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

Test(new, lt_int)
{
    Object  *point = new(Int, 40);
    Object  *point2 = new(Int, 41);

    cr_assert_eq(lt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, gt_int)
{
    Object  *point = new(Int, 42);
    Object  *point2 = new(Int, 41);

    cr_assert_eq(gt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, eq_int)
{
    Object  *point = new(Int, 41);
    Object  *point2 = new(Int, 41);

    cr_assert_eq(eq(point, point2), 1);
    delete(point2);
    delete(point);
}