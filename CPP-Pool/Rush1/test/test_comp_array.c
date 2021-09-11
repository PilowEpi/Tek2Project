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
#include "array.h"

Test(new, gt_array)
{
    Object  *array = new(Array, 3, Int, 0);
    Object  *array2 = new(Array, 3, Int, 1);
    Object  *it = begin(array);
    Object  *it_end = end(array2);
    
    cr_assert_eq(gt(it, it_end), 0);
    delete(it);
    delete(it_end);
    delete(array);
    delete(array2);
}

Test(new, eq_array)
{
    Object  *array = new(Array, 3, Int, 0);
    Object  *array2 = new(Array, 3, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = begin(array2);
    
    cr_assert_eq(eq(getval(it), getval(it_end)), 1);
    delete(it);
    delete(it_end);
    delete(array);
    delete(array2);
}