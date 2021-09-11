/*
** EPITECH PROJECT, 2021
** teams
** File description:
** use
*/

#include <stdlib.h>
#include <stdio.h>

#include "server.h"

void uset(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split(buf);
    int i = 0;
    uuid_t id;
    char test[UUID_LENGTH];

    uuid_clear(id);
    for (; cmd[i]; i++);
    if (i > 2 || (i == 2 && uuid_parse(cmd[1], id))) {
        dprintf(usr->fd, MATR);
        return;
    }
    uuid_copy(usr->user->team, id);
    uuid_unparse_upper(id, test);
    save_regs(srv->regs);
    free(cmd);
}

void usec(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split(buf);
    int i = 0;
    uuid_t id;

    uuid_clear(id);
    for (; cmd[i]; i++);
    if (i > 2 || (i == 2 && uuid_parse(cmd[1], id))) {
        dprintf(usr->fd, MATR);
        return;
    }
    uuid_copy(usr->user->channel, id);
    save_regs(srv->regs);
    free(cmd);
}

void usetr(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split(buf);
    int i = 0;
    uuid_t id;

    uuid_clear(id);
    for (; cmd[i]; i++);
    if (i > 2 || (i == 2 && uuid_parse(cmd[1], id))) {
        dprintf(usr->fd, MATR);
        return;
    }
    uuid_copy(usr->user->thread, id);
    save_regs(srv->regs);
    free(cmd);
}
