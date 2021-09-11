/*
** EPITECH PROJECT, 2021
** teams
** File description:
** print single item
*/

#include <stdlib.h>

#include "logging_client.h"
#include "cli.h"

int pr_user(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_user(buf[1], buf[2], atoi(buf[3]));
    return (0);
}

int pr_team(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_team(buf[1], buf[2], buf[3]);
    return (0);
}

int pr_channel(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_channel(buf[1], buf[2], buf[3]);
    return (0);
}

int pr_thread(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 6)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_print_thread(buf[1], buf[2], tm, buf[4], buf[5]);
    return (0);
}
