/*
** EPITECH PROJECT, 2021
** teams
** File description:
** broadcast
*/

#include <stdio.h>

#include "logging_server.h"
#include "server.h"

void broad_login(server_t *srv, user_t *usr)
{
    char id[UUID_LENGTH];

    if (!usr)
        return;
    uuid_unparse_upper(usr->id, id);
    server_event_user_logged_in(id);
    for (int i = 0; srv->conns[i]; i++) {
        if (!srv->conns[i]->user)
            continue;
        dprintf(srv->conns[i]->fd, "TCP EV1 \"%s\" \"%s\"\n",
            id, usr->username);
    }
}

void broad_logout(server_t *srv, user_t *usr)
{
    char id[UUID_LENGTH];

    if (!usr)
        return;
    uuid_unparse_upper(usr->id, id);
    server_event_user_logged_out(id);
    for (int i = 0; srv->conns[i]; i++) {
        if (!srv->conns[i]->user)
            continue;
        dprintf(srv->conns[i]->fd, "TCP EV2 \"%s\" \"%s\"\n",
            id, usr->username);
    }
}
