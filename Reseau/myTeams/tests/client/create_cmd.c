/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(create, create_one_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", NULL};

    create(2, buf, 1);
    cr_assert_stdout_eq_str("TCP CREATE \"test\"\n");
}

Test(create, create_two_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    create(4, buf, 1);
    create(3, buf, 1);
    cr_assert_stdout_eq_str("TCP CREATE \"test\" \"test\"\n");
}

Test(info, create_two_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    info(3, buf, 1);
    info(1, buf, 1);
    cr_assert_stdout_eq_str("TCP INFO\n");
}