/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(ev_lin, ev_lin_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", NULL};

    cr_assert_eq(ev_lin(1, buf), 1);
    cr_assert_eq(ev_lin(3, buf), 0);
}

Test(ev_lout, ev_lout_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", NULL};

    cr_assert_eq(ev_lout(2, buf), 1);
    cr_assert_eq(ev_lout(3, buf), 0);
}

Test(ev_private, ev_private_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", NULL};


    cr_assert_eq(ev_private(1, buf), 1);
    cr_assert_eq(ev_private(3, buf), 0);
}

Test(ev_thr_rep, ev_thr_rep_, .init = redirect_all_std)
{
    char *buf[] = {"toto", "titi", "tutu", "lul", "xd", NULL};


    cr_assert_eq(ev_thr_rep(1, buf), 1);
    cr_assert_eq(ev_thr_rep(5, buf), 0);
}