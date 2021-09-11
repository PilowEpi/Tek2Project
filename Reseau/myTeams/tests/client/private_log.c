/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(pr_private, pr_user_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_private(1, buf), 1);
    cr_assert_eq(pr_private(4, buf), 0);
}

Test(err_unauth, pr_team_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(err_unauth(2, buf), 1);
    cr_assert_eq(err_unauth(1, buf), 0);
}