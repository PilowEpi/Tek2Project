/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(pr_user_list, pr_user_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_user_list(1, buf), 1);
    cr_assert_eq(pr_user_list(4, buf), 0);
}

Test(pr_team_list, pr_team_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_team_list(2, buf), 1);
    cr_assert_eq(pr_team_list(4, buf), 0);
}

Test(pr_channel_list, pr_channel_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(pr_channel_list(2, buf), 1);
    cr_assert_eq(pr_channel_list(4, buf), 0);
}

Test(pr_thread_list, pr_thread_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(pr_thread_list(1, buf), 1);
    cr_assert_eq(pr_thread_list(6, buf), 0);
}

Test(pr_reply_list,pr_reply_list_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(pr_reply_list(1, buf), 1);
    cr_assert_eq(pr_reply_list(5, buf), 0);
}