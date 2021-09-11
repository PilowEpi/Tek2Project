/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(cr_team, create_team, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "lul", "lul", NULL};

    cr_assert_eq(cr_team(1, buf), 1);
    cr_assert_eq(cr_team(4, buf), 0);
}

Test(cr_channel, create_team, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "lul", "lul", NULL};

    cr_assert_eq(cr_channel(1, buf), 1);
    cr_assert_eq(cr_channel(4, buf), 0);
}

Test(cr_thread, cr_thread_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(cr_thread(1, buf), 1);
    cr_assert_eq(cr_thread(6, buf), 0);
}

Test(cr_reply, cr_reply_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(cr_reply(1, buf), 1);
    cr_assert_eq(cr_reply(5, buf), 0);
}