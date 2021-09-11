/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(help, help_empty_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", NULL};

    help(2, buf, 1);
    cr_assert_str_neq("help", buf[1]);
}

Test(list, help_one_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    help(1, buf, 1);
    cr_assert_str_neq("help", buf[1]);
}