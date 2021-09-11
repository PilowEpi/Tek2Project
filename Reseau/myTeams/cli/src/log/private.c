/*
** EPITECH PROJECT, 2021
** teams
** File description:
** private messages
*/

#include "logging_client.h"
#include "cli.h"

int pr_private(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 4)
        return (1);
    strptime(buf[2], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_private_message_print_messages(buf[1], tm, buf[3]);
    return (0);
}

int err_unauth(int len, char **buf)
{
    if (len != 1)
        return (1);
    client_error_unauthorized();
    return (0);
}
