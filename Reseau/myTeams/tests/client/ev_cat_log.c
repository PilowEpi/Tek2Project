/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(ev_team, ev_team_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(ev_team(1, buf), 1);
    cr_assert_eq(ev_team(4, buf), 0);
}

Test(ev_channel, ev_channel_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", NULL};

    cr_assert_eq(ev_channel(2, buf), 1);
    cr_assert_eq(ev_channel(4, buf), 0);
}

Test(ev_thread, ev_thread_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "tutu", "tutu", "tutu", NULL};


    cr_assert_eq(ev_thread(1, buf), 1);
    cr_assert_eq(ev_thread(6, buf), 0);
}