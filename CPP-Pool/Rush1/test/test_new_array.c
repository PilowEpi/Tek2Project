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

Test(new, new_and_delete_array)
{
    Object  *array = new(Array, 10, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);
    char *test = 0;

    while (lt(it, it_end)) {
        test = str(getval(it));
        cr_assert_str_eq(test, "<Int (0)>");
        incr(it);
        free(test);
    }
    delete(it);
    delete(it_end);
    delete(array);
}

Test(new, setval_in_array)
{
    Object  *array = new(Array, 3, Int, 0);
    Object  *it = begin(array);
    Object  *it_end = end(array);
    char *test = 0;

    setitem(array, 0, 1);
    setitem(array, 1, 1);
    setitem(array, 2, 1);

    while (lt(it, it_end)) {
        test = str(getval(it));
        cr_assert_str_eq(test, "<Int (1)>");
        incr(it);
        free(test);
    }
    delete(it);
    delete(it_end);
    delete(array); 
}