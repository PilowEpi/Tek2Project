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

Test(new, lt_float)
{
    Object  *point = new(Float, 40.1f);
    Object  *point2 = new(Float, 40.2f);

    cr_assert_eq(lt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, gt_float)
{
    Object  *point = new(Float, 40.1f);
    Object  *point2 = new(Float, 40.0f);

    cr_assert_eq(gt(point, point2), 1);
    delete(point2);
    delete(point);
}

Test(new, eq_float)
{
    Object  *point = new(Float, 41.0f);
    Object  *point2 = new(Float, 41.0f);

    cr_assert_eq(eq(point, point2), 1);
    delete(point2);
    delete(point);
}