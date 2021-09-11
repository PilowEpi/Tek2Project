/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "logging_client.h"
#include "cli.h"

int ev_team(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_event_team_created(buf[1], buf[2], buf[3]);
    return (0);
}

int ev_channel(int len, char **buf)
{
    if (len != 4)
        return (1);
    client_event_channel_created(buf[1], buf[2], buf[3]);
    return (0);
}

int ev_thread(int len, char **buf)
{
    struct tm time;
    time_t tm;

    if (len != 6)
        return (1);
    strptime(buf[3], "%Y-%m-%d %H:%M:%S", &time);
    tm = mktime(&time);
    client_event_thread_created(buf[1], buf[2], tm, buf[4], buf[5]);
    return (0);
}
