/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(list, list_one_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    list(2, buf, 1);
    list(1, buf, 1);
    cr_assert_stdout_eq_str("TCP LIST\n");
}