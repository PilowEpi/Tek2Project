/*
** EPITECH PROJECT, 2021
** teams
** File description:
** utils
*/

#include "server.h"

team_t *find_team_id(uuid_t id, server_t *srv)
{
    for (int i = 0; srv->teams[i] != 0; i++) {
        if (!uuid_compare(srv->teams[i]->id, id))
            return (srv->teams[i]);
    }
    return (0);
}

chan_t *find_chan_id(uuid_t id, team_t *team)
{
    for (int i = 0; team->channels[i] != 0; i++) {
        if (!uuid_compare(team->channels[i]->id, id))
            return (team->channels[i]);
    }
    return (0);
}

thread_t *find_thread_id(uuid_t id, chan_t *chan)
{
    for (int i = 0; chan->threads[i] != 0; i++) {
        if (!uuid_compare(chan->threads[i]->id, id))
            return (chan->threads[i]);
    }
    return (0);
}

thread_t *get_current_thread(user_t *usr, server_t *srv)
{
    team_t *team = find_team_id(usr->team, srv);
    chan_t *chan = find_chan_id(usr->channel, team);
    thread_t *thread = find_thread_id(usr->thread, chan);

    return (thread);
}

int is_user_in_team(user_t *user, uuid_t team)
{
    if (!user)
        return (0);
    for (int i = 0; !uuid_is_null(user->subbed[i]); i++) {
        if (!uuid_compare(user->subbed[i], team))
            return (1);
    }
    return (0);
}
