/*
** EPITECH PROJECT, 2021
** teams
** File description:
** list cmd
*/

#include <stdio.h>

#include "server.h"

void list_teams(char *buf, conn_t *usr, server_t *srv)
{
    char id[UUID_LENGTH];

    for (int i = 0; srv->teams[i]; i++) {
        uuid_unparse_upper(srv->teams[i]->id, id);
        dprintf(usr->fd, "TCP EV9 \"%s\" \"%s\" \"%s\"\n",
            id, srv->teams[i]->name, srv->teams[i]->desc);
    }
}

void list_channels(char *buf, conn_t *usr, server_t *srv)
{
    char id[UUID_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);

    if (!check_auth(usr, usr->user->team))
        return;
    for (int i = 0; team->channels[i]; i++) {
        uuid_unparse_upper(team->channels[i]->id, id);
        dprintf(usr->fd, "TCP EV10 \"%s\" \"%s\" \"%s\"\n",
            id, team->channels[i]->name, team->channels[i]->desc);
    }
}

void list_threads(char *buf, conn_t *usr, server_t *srv)
{
    char time[TIME_LENGTH];
    char id[UUID_LENGTH];
    char user[UUID_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = find_chan_id(usr->user->channel, team);
    time_t cpy;

    if (!check_auth(usr, usr->user->team))
        return;
    for (int i = 0; chan->threads[i]; i++) {
        cpy = chan->threads[i]->time;
        strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
        uuid_unparse_upper(chan->threads[i]->id, id);
        uuid_unparse_upper(chan->threads[i]->user, user);
        dprintf(usr->fd, "TCP EV11 \"%s\" \"%s\" \"%s\" \"%s\" \"%s\"\n",
            id, user, time, chan->threads[i]->title, chan->threads[i]->content);
    }
}

void list_replies(char *buf, conn_t *usr, server_t *srv)
{
    char user[UUID_LENGTH];
    char t_id[UUID_LENGTH];
    char time[TIME_LENGTH];
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = find_chan_id(usr->user->channel, team);
    thread_t *thread = find_thread_id(usr->user->thread, chan);
    time_t cpy;

    if (!check_auth(usr, usr->user->team))
        return;
    uuid_unparse_upper(thread->id, t_id);
    for (int i = 0; thread->messages[i]; i++) {
        cpy = thread->messages[i]->time;
        strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
        uuid_unparse_upper(thread->messages[i]->user, user);
        dprintf(usr->fd, "TCP EV12 \"%s\" \"%s\" \"%s\" \"%s\"\n",
            t_id, user, time, thread->messages[i]->content);
    }
}

void list(char *buf, conn_t *usr, server_t *srv)
{
    if (uuid_is_null(usr->user->team)) {
        list_teams(buf, usr, srv);
        return;
    } else if (uuid_is_null(usr->user->channel)){
        if (!g_team(usr, srv))
            return;
        list_channels(buf, usr, srv);
        return;
    }
    if (uuid_is_null(usr->user->thread)) {
        if (!g_chan(usr, srv))
            return;
        list_threads(buf, usr, srv);
    } else if (g_thread(usr, srv)) {
        list_replies(buf, usr, srv);
    }
}
