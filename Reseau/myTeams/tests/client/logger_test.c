/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "tests.h"

Test(log_other, log_other_, .init = redirect_all_std)
{
    char *buf = "toto";

    log_other(buf);
    cr_assert_str_eq(buf, "toto");
}

Test(log_msg, log_msg_, .init = redirect_all_std)
{
    char *buf = strdup("/login \"toto\"");

    log_msg(buf);
    cr_assert_str_neq(buf, "toto");
}

Test(forward_logger, forward_logger_, .init = redirect_all_std)
{
    char *buf = strdup("/login \"toto\"");

    forward_logger(buf);
    cr_assert_str_neq(buf, "toto");
}