/*
** EPITECH PROJECT, 2021
** teams
** File description:
** broadcast creation
*/

#include <stdio.h>

#include "server.h"
#include "logging_server.h"

void broad_team(team_t *team, conn_t *usr, server_t *srv)
{
    char user[UUID_LENGTH];
    char id[UUID_LENGTH];

    uuid_unparse_upper(usr->user->id, user);
    uuid_unparse_upper(team->id, id);
    server_event_team_created(id, team->name, user);
    for (int i = 0; srv->conns[i]; i++) {
        if (!is_user_in_team(srv->conns[i]->user, team->id))
            continue;
        dprintf(srv->conns[i]->fd, "TCP EV5 \"%s\" \"%s\" \"%s\"\n",
            id, team->name, team->desc);
    }
    dprintf(usr->fd, "TCP EV24 \"%s\" \"%s\" \"%s\"\n",
        id, team->name, team->desc);
}

void broad_chan(chan_t *chan, conn_t *usr, server_t *srv)
{
    char id[UUID_LENGTH];
    char t_id[UUID_LENGTH];

    uuid_unparse_upper(chan->id, id);
    uuid_unparse_upper(usr->user->team, t_id);
    server_event_channel_created(t_id, id, chan->name);
    for (int i = 0; srv->conns[i]; i++) {
        if (!is_user_in_team(srv->conns[i]->user, usr->user->team))
            continue;
        dprintf(srv->conns[i]->fd, "TCP EV6 \"%s\" \"%s\" \"%s\"\n",
            id, chan->name, chan->desc);
    }
    dprintf(usr->fd, "TCP EV25 \"%s\" \"%s\" \"%s\"\n",
        id, chan->name, chan->desc);
}

void broad_thread(thread_t *thr, conn_t *usr, server_t *srv)
{
    char time[TIME_LENGTH];
    char id[UUID_LENGTH];
    char user[UUID_LENGTH];
    char chan[UUID_LENGTH];
    time_t cpy = thr->time;

    uuid_unparse_upper(thr->id, id);
    uuid_unparse_upper(usr->user->id, user);
    uuid_unparse_upper(usr->user->channel, chan);
    server_event_thread_created(chan, id, user, thr->title, thr->content);
    strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
    dprintf(usr->fd, "TCP EV26 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
        id, user, time, thr->title, thr->content);
    for (int i = 0; srv->conns[i]; i++) {
        if (!is_user_in_team(srv->conns[i]->user, usr->user->team))
           continue;
        dprintf(srv->conns[i]->fd,
            "TCP EV7 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
            id, user, time, thr->title, thr->content);
    }
}

void broad_reply(msg_t *msg, conn_t *usr, server_t *srv)
{
    char time[TIME_LENGTH];
    char t_id[UUID_LENGTH];
    char team[UUID_LENGTH];
    char user[UUID_LENGTH];
    time_t cpy = msg->time;

    uuid_unparse_upper(usr->user->thread, t_id);
    uuid_unparse_upper(usr->user->team, team);
    uuid_unparse_upper(msg->user, user);
    server_event_reply_created(t_id, user, msg->content);
    strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
    dprintf(usr->fd, "TCP EV27 \"%s\" \"%s\" \"%s\" \"%s\"\n",
        t_id, user, time, msg->content);
    for (int i = 0; srv->conns[i]; i++) {
        if (!is_user_in_team(srv->conns[i]->user, usr->user->team))
            continue;
        dprintf(srv->conns[i]->fd, "TCP EV4 \"%s\" \"%s\" \"%s\" \"%s\"\n",
            team, t_id, user, msg->content);
    }
}
