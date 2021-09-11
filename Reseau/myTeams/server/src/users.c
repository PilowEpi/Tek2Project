/*
** EPITECH PROJECT, 2021
** teams
** File description:
** users utils
*/

#include <stdlib.h>
#include <stdio.h>

#include "server.h"

user_t *find_user_id(uuid_t id, server_t *srv)
{
    for (int i = 0; srv->regs[i]; i++) {
        if (!uuid_compare(srv->regs[i]->id, id))
            return (srv->regs[i]);
    }
    return (0);
}

void send_elem(conn_t *conn, msg_t *msg)
{
    char time[TIME_LENGTH];
    char id[UUID_LENGTH];
    time_t cpy = msg->time;

    strftime(time, TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&cpy));
    uuid_unparse_upper(msg->user, id);
    dprintf(conn->fd, "TCP EV13 \"%s\" \"%s\" \"%s\"\n",
        id, time, msg->content);
}

void hmes(char *buf, conn_t *conn, server_t *srv)
{
    char **cmd = split_expect(buf, conn->fd, 2);
    uuid_t other;

    if (!cmd)
        return;
    uuid_clear(other);
    uuid_parse(cmd[1], other);
    if (!find_user_id(other, srv)) {
        dprintf(conn->fd, "TCP EV17 \"%s\"\n", cmd[1]);
        return;
    }
    for (int i = 0; conn->user->private[i]; i++) {
        if (uuid_compare(conn->user->private[i]->user, conn->user->id) &&
            uuid_compare(conn->user->private[i]->user, other))
            continue;
        send_elem(conn, conn->user->private[i]);
    }
    free(cmd);
}

void user(char *buf, conn_t *conn, server_t *srv)
{
    char **cmd = split_expect(buf, conn->fd, 2);
    char id[UUID_LENGTH];
    uuid_t other;
    user_t *found;

    if (!cmd)
        return;
    if (uuid_parse(cmd[1], other)) {
        dprintf(conn->fd, ROGM);
        return;
    }
    found = find_user_id(other, srv);
    if (!found) {
        dprintf(conn->fd, "TCP EV17 \"%s\"\n", cmd[1]);
        return;
    }
    dprintf(conn->fd, "TCP EV20 \"%s\" \"%s\" \"%d\"\n",
        cmd[1], found->username, is_user_connected(found->id, srv));
    free(cmd);
}

void users(char *buf, conn_t *conn, server_t *srv)
{
    char id[UUID_LENGTH];

    for (int i = 0; srv->regs[i]; i++) {
        uuid_unparse_upper(srv->regs[i]->id, id);
        dprintf(conn->fd, "TCP EV8 \"%s\" \"%s\" \"%d\"\n",
            id, srv->regs[i]->username,
            is_user_connected(srv->regs[i]->id, srv));
    }
}
