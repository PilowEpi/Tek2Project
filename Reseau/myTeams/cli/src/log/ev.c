/*
** EPITECH PROJECT, 2021
** teams
** File description:
** log events
*/

#include "logging_client.h"

int ev_lin(int len, char **buf)
{
    if (len != 3)
        return (1);
    client_event_logged_in(buf[1], buf[2]);
    return (0);
}

int ev_lout(int len, char **buf)
{
    if (len != 3)
        return (1);
    client_event_logged_out(buf[1], buf[2]);
    return (0);
}

int ev_private(int len, char **buf)
{
    if (len != 3)
        return (1);
    client_event_private_message_received(buf[1], buf[2]);
    return (0);
}

int ev_thr_rep(int len, char **buf)
{
    if (len != 5)
        return (1);
    client_event_thread_reply_received(buf[1], buf[2], buf[3], buf[4]);
    return (0);
}
