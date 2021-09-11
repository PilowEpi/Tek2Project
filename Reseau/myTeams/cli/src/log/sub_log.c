/*
** EPITECH PROJECT, 2021
** teams
** File description:
** sub
*/

#include "logging_client.h"

int pr_sub(int len, char **buf)
{
    if (len != 3)
        return (1);
    client_print_subscribed(buf[1], buf[2]);
    return (0);
}

int pr_unsub(int len, char **buf)
{
    if (len != 3)
        return (1);
    client_print_unsubscribed(buf[1], buf[2]);
    return (0);
}
