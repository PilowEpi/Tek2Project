/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(pr_sub, pr_sub_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", NULL};

    cr_assert_eq(pr_sub(1, buf), 1);
    cr_assert_eq(pr_sub(3, buf), 0);
}

Test(pr_unsub, pr_unsub_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", NULL};

    cr_assert_eq(pr_unsub(2, buf), 1);
    cr_assert_eq(pr_unsub(3, buf), 0);
}