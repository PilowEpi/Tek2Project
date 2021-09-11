/*
** EPITECH PROJECT, 2021
** myteams
** File description:
** auth check
*/

#include <stdio.h>

#include "server.h"

int check_auth(conn_t *usr, uuid_t team)
{
    if (!is_user_in_team(usr->user, team)) {
        dprintf(usr->fd, "TCP EV18\n");
        return (0);
    }
    return (1);
}

int ck_t(conn_t *usr, char *thr, server_t *srv)
{
    if (!is_user_in_team(usr->user, usr->user->team))
        return (0);
    if (exist_thr(thr, srv, usr->user)) {
        dprintf(usr->fd, "TCP EV19\n");
        return (0);
    }
    return (1);
}

int ck_c(conn_t *usr, char *chan, server_t *srv)
{
    if (!is_user_in_team(usr->user, usr->user->team))
        return (0);
    if (exist_cn(chan, srv, usr->user)) {
        dprintf(usr->fd, "TCP EV19\n");
        return (0);
    }
    return (1);
}

int ck_m(conn_t *usr, char *team, server_t *srv)
{
    if (exist_team(team, srv)) {
        dprintf(usr->fd, "TCP EV19\n");
        return (0);
    }
    return (1);
}

int ck_a(conn_t *usr)
{
    return (is_user_in_team(usr->user, usr->user->team));
}
