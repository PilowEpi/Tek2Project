/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(users, users_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", "LUL", NULL};

    users(2, buf, 1);
    users(1, buf, 1);
    cr_assert_stdout_eq_str("TCP USERS\n");
}

Test(user, user_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", "LUL", NULL};

    user(1, buf, 1);
    user(2, buf, 1);
    cr_assert_stdout_eq_str("TCP USER toto\n");
}

Test(sendc, sendc_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", "LUL", NULL};

    sendc(2, buf, 1);
    sendc(3, buf, 1);
    cr_assert_stdout_eq_str("TCP MES \"toto\" \"tptp\"\n");
}

Test(messages, messages_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "toto", "tptp", "LUL", NULL};

    messages(1, buf, 1);
    messages(2, buf, 1);
    cr_assert_stdout_eq_str("TCP HMES toto\n");
}