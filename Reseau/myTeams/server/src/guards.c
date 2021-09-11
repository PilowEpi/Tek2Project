/*
** EPITECH PROJECT, 2021
** teams
** File description:
** check existence guards
*/

#include <stdio.h>

#include "server.h"

int g_team(conn_t *conn, server_t *srv)
{
    team_t *team = find_team_id(conn->user->team, srv);
    char id[UUID_LENGTH];

    uuid_unparse_upper(conn->user->team, id);
    if (team)
        return (1);
    dprintf(conn->fd, "TCP EV14 \"%s\"\n", id);
    return (0);
}

int g_chan(conn_t *conn, server_t *srv)
{
    team_t *team;
    chan_t *chan;
    char id[UUID_LENGTH];

    uuid_unparse_upper(conn->user->channel, id);
    if (!g_team(conn, srv))
        return (0);
    team = find_team_id(conn->user->team, srv);
    chan = find_chan_id(conn->user->channel, team);
    if (chan)
        return (1);
    dprintf(conn->fd, "TCP EV15 \"%s\"\n", id);
    return (0);
}

int g_thread(conn_t *conn, server_t *srv)
{
    team_t *team;
    chan_t *chan;
    thread_t *thread;
    char id[UUID_LENGTH];

    uuid_unparse_upper(conn->user->thread, id);
    if (!g_chan(conn, srv))
        return (0);
    team = find_team_id(conn->user->team, srv);
    chan = find_chan_id(conn->user->channel, team);
    thread = find_thread_id(conn->user->thread, chan);
    if (thread)
        return (1);
    dprintf(conn->fd, "TCP EV16 \"%s\"\n", id);
    return (0);
}
