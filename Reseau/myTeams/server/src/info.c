/*
** EPITECH PROJECT, 2021
** teams
** File description:
** info cmd
*/

#include <stdio.h>

#include "server.h"

void info_logged(char *buf, conn_t *usr, server_t *srv)
{
    char user[UUID_LENGTH];

    for (int i = 0; srv->conns[i]; i++) {
        uuid_unparse_upper(srv->conns[i]->user->id, user);
        dprintf(usr->fd, "TCP EV20 \"%s\" \"%s\" \"%d\"\n",
            user, srv->conns[i]->user->username, 1);
    }
}

void info_team(char *buf, conn_t *usr, server_t *srv)
{
    char id[UUID_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);

    if (!check_auth(usr, usr->user->team))
        return;
    uuid_unparse_upper(team->id, id);
    dprintf(usr->fd, "TCP EV21 \"%s\" \"%s\" \"%s\"\n",
        id, team->name, team->desc);
}

void info_channel(char *buf, conn_t *usr, server_t *srv)
{
    char id[UUID_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = find_chan_id(usr->user->channel, team);

    if (!check_auth(usr, usr->user->team))
        return;
    uuid_unparse_upper(chan->id, id);
    dprintf(usr->fd, "TCP EV22 \"%s\" \"%s\" \"%s\"\n",
        id, chan->name, chan->desc);
}

void info_thread(char *buf, conn_t *usr, server_t *srv)
{
    char time[TIME_LENGTH];
    char id[UUID_LENGTH];
    char user[UUID_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = find_chan_id(usr->user->channel, team);
    thread_t *thread = find_thread_id(usr->user->thread, chan);
    time_t cpy = thread->time;

    if (!check_auth(usr, usr->user->team))
        return;
    strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
    uuid_unparse_upper(thread->id, id);
    uuid_unparse_upper(thread->user, user);
    dprintf(usr->fd, "TCP EV23 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
        id, user, time, thread->title, thread->content);
}

void info(char *buf, conn_t *usr, server_t *srv)
{
    if (uuid_is_null(usr->user->team)) {
        info_logged(buf, usr, srv);
        return;
    } else if (uuid_is_null(usr->user->channel)){
        if (!g_team(usr, srv))
            return;
        info_team(buf, usr, srv);
        return;
    }
    if (uuid_is_null(usr->user->thread)) {
        if (!g_chan(usr, srv))
            return;
        info_channel(buf, usr, srv);
    } else if (g_thread(usr, srv)) {
        info_thread(buf, usr, srv);
    }
}
