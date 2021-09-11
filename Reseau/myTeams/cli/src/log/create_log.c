/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create
*/

#include "logging_client.h"
#include "cli.h"

int cr_team(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_team_created(buf[1], buf[2], buf[3]);
    return (0);
}

int cr_channel(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_print_channel_created(buf[1], buf[2], buf[3]);
    return (0);
}

int cr_thread(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 6)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_print_thread_created(buf[1], buf[2], tm, buf[4], buf[5]);
    return (0);
}

int cr_reply(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 5)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_print_reply_created(buf[1], buf[2], tm, buf[4]);
    return (0);
}
