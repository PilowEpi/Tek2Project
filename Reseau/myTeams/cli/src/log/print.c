/*
** EPITECH PROJECT, 2021
** teams
** File description:
** print ev
*/

#include <stdlib.h>

#include "logging_client.h"
#include "cli.h"

int pr_user_list(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_users(buf[1], buf[2], atoi(buf[3]));
    return (0);
}

int pr_team_list(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_teams(buf[1], buf[2], buf[3]);
    return (0);
}

int pr_channel_list(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_team_print_channels(buf[1], buf[2], buf[3]);
    return (0);
}

int pr_thread_list(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 6)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_channel_print_threads(buf[1], buf[2], tm, buf[4], buf[5]);
    return (0);
}

int pr_reply_list(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 5)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_thread_print_replies(buf[1], buf[2], tm, buf[4]);
    return (0);
}
