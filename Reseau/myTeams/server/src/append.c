/*
** EPITECH PROJECT, 2021
** teas
** File description:
** append objs
*/

#include <stdlib.h>
#include <err.h>

#include "server.h"

void append_team(server_t *srv, team_t *team)
{
    int i = 0;

    for (; srv->teams[i] != 0; i++);
    srv->teams = reallocarray(srv->teams, i + 2, sizeof(team_t *));
    if (!srv->teams)
        errx(84, "realloc failed");
    srv->teams[i] = team;
    srv->teams[i + 1] = 0;
}

void append_channel(team_t *team, chan_t *chan)
{
    int i = 0;

    for (; team->channels[i] != 0; i++);
    team->channels = reallocarray(team->channels, i + 2, sizeof(chan_t *));
    if (!team->channels)
        errx(84, "realloc failed");
    team->channels[i] = chan;
    team->channels[i + 1] = 0;
}

void append_thread(chan_t *chan, thread_t *thread)
{
    int i = 0;

    for (; chan->threads[i] != 0; i++);
    chan->threads = reallocarray(chan->threads, i + 2, sizeof(thread_t *));
    if (!chan->threads)
        errx(84, "realloc failed");
    chan->threads[i] = thread;
    chan->threads[i + 1] = 0;
}

void append_reply(thread_t *thread, msg_t *msg)
{
    int i = 0;

    for (; thread->messages[i] != 0; i++);
    thread->messages = reallocarray(thread->messages, i + 2, sizeof(msg_t *));
    if (!thread->messages)
        errx(84, "realloc failed");
    thread->messages[i] = msg;
    thread->messages[i + 1] = 0;
}
