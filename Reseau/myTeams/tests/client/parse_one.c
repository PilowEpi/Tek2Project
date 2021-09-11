/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(parse, help_one_cmd, .init = redirect_all_std)
{
    char *cmd = strdup("/help");
    char *err = strdup("/help \"toto\"");

    parse(err, 1);
    parse(cmd, 1);
    free(err);
    free(cmd);
}

Test(parse, login_one_cmd, .init = redirect_all_std)
{
    char *err = strdup("/login");
    char *cmd = strdup("/login \"toto\"");

    parse(err, 1);
    parse(cmd, 1);
    free(err);
    free(cmd);
}

Test(parse, logout_one_cmd, .init = redirect_all_std)
{
    char *err = strdup("/logout");
    char *cmd = strdup("/logout \"toto\"");

    parse(err, 1);
    parse(cmd, 1);
    free(err);
    free(cmd);
}

Test(parse, logout_wrong_cmd, .init = redirect_all_std)
{
    char *err = strdup("/wrong");
    char *cmd = strdup("/wrong \"toto\"");

    parse(err, 1);
    parse(cmd, 1);
    free(err);
    free(cmd);
}