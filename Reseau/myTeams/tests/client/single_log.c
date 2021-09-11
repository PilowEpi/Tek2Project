/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(pr_user, pr_user_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_user(1, buf), 1);
    cr_assert_eq(pr_user(4, buf), 0);
}

Test(pr_team, pr_team_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_team(2, buf), 1);
    cr_assert_eq(pr_team(4, buf), 0);
}

Test(pr_channel, pr_channel_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_channel(2, buf), 1);
    cr_assert_eq(pr_channel(4, buf), 0);
}

Test(pr_thread, pr_thread_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(pr_thread(1, buf), 1);
    cr_assert_eq(pr_thread(6, buf), 0);
}