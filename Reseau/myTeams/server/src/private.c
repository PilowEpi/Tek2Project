/*
** EPITECH PROJECT, 2021
** teams
** File description:
** private messages
*/

#include <err.h>
#include <stdio.h>
#include <stdlib.h>

#include "server.h"
#include "logging_server.h"

void append_msg(user_t *usr, msg_t *msg)
{
    int i = 0;

    for (; usr->private[i] != 0; i++);
    usr->private = reallocarray(usr->private, i + 2, sizeof(msg_t *));
    if (!usr->private)
        errx(84, "realloc failed");
    usr->private[i] = msg;
    usr->private[i + 1] = 0;
}

void try_send(char *sender, msg_t *msg, user_t *found, server_t *srv)
{
    for (int i = 0; srv->conns[i]; i++) {
        if (srv->conns[i]->user == found) {
            dprintf(srv->conns[i]->fd, "TCP EV3 \"%s\" \"%s\"\n",
                sender, msg->content);
        }
    }
}

void create_msg(conn_t *conn, char *body, user_t *found, server_t *srv)
{
    msg_t *msg = malloc(sizeof(msg_t));
    char sender[UUID_LENGTH];
    char receiver[UUID_LENGTH];

    uuid_unparse_upper(conn->user->id, sender);
    uuid_unparse_upper(found->id, receiver);
    if (!msg)
        errx(84, "malloc failed");
    if (init_message(msg, body, conn)) {
        dprintf(conn->fd, ROGM);
        return;
    }
    append_msg(conn->user, msg);
    append_msg(found, msg);
    server_event_private_message_sended(sender, receiver, body);
    try_send(sender, msg, found, srv);
}

void mes(char *buf, conn_t *conn, server_t *srv)
{
    char **cmd = split_expect_quoted(buf, conn->fd, 3);
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
    create_msg(conn, cmd[2], found, srv);
    save_regs(srv->regs);
    free(cmd);
}
