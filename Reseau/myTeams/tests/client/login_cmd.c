/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(login, login_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    login(1, buf, 1);
    login(2, buf, 1);
    cr_assert_stdout_eq_str("TCP LOGIN test\n");
}

Test(logout, logout_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    logout(2, buf, 1);
    logout(1, buf, 1);
    cr_assert_stdout_eq_str("TCP LOGOUT\n");
}