/*
** EPITECH PROJECT, 2021
** teams
** File description:
** test use cmd
*/

#include "tests.h"

Test(subscribe, subscribe_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    subscribe(1, buf, 1);
    subscribe(2, buf, 1);
    cr_assert_stdout_eq_str("TCP SUB test\n");
}

Test(unsubscribe, unsubscribe_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    unsubscribe(1, buf, 1);
    unsubscribe(2, buf, 1);
    cr_assert_stdout_eq_str("TCP UNSUB test\n");
}

Test(subscribed, subscribed_one_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    subscribed(1, buf, 1);
    cr_assert_stdout_eq_str("TCP SUB?\n");
}


Test(subscribed, subscribed_two_cmd, .init = redirect_all_std)
{
    char *buf[] = {"test", "test", "test", NULL};

    subscribed(2, buf, 1);
    cr_assert_stdout_eq_str("TCP SUB? test\n");
}
