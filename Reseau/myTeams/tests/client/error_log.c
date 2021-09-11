/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(err_team, err_team_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", NULL};

    cr_assert_eq(err_team(1, buf), 1);
    cr_assert_eq(err_team(2, buf), 0);
}

Test(err_channel, err_channel_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", NULL};

    cr_assert_eq(err_channel(1, buf), 1);
    cr_assert_eq(err_channel(2, buf), 0);
}

Test(err_thread, err_thread_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", NULL};

    cr_assert_eq(err_thread(1, buf), 1);
    cr_assert_eq(err_thread(2, buf), 0);
}

Test(err_user, err_user_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", NULL};

    cr_assert_eq(err_user(1, buf), 1);
    cr_assert_eq(err_user(2, buf), 0);
}

Test(err_exists, err_exists_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", NULL};

    cr_assert_eq(err_exists(2, buf), 1);
    cr_assert_eq(err_exists(1, buf), 0);
}