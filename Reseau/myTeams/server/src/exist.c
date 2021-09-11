/*
** EPITECH PROJECT, 2021
** teams
** File description:
** check already exists
*/

#include <string.h>

#include "server.h"

int exist_team(char *name, server_t *srv)
{
    for (int i = 0; srv->teams[i]; i++) {
        if (!strcmp(name, srv->teams[i]->name))
            return (1);
    }
    return (0);
}

int exist_cn(char *name, server_t *srv, user_t *user)
{
    team_t *team = find_team_id(user->team, srv);

    for (int i = 0; team->channels[i]; i++) {
        if (!strcmp(name, team->channels[i]->name))
            return (1);
    }
    return (0);
}

int exist_thr(char *name, server_t *srv, user_t *user)
{
    team_t *team = find_team_id(user->team, srv);
    chan_t *chan = find_chan_id(user->channel, team);

    for (int i = 0; chan->threads[i]; i++) {
        if (!strcmp(name, chan->threads[i]->title))
            return (1);
    }
    return (0);
}
