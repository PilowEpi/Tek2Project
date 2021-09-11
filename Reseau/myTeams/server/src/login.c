/*
** EPITECH PROJECT, 2021
** teams
** File description:
** login
*/

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <err.h>

#include "logging_server.h"
#include "server.h"

void init_user(user_t *usr, char *name)
{
    char id[UUID_LENGTH];

    memset(usr->username, 0, MAX_NAME_LENGTH);
    strcpy(usr->username, name);
    uuid_generate_random(usr->id);
    uuid_clear(usr->team);
    uuid_clear(usr->channel);
    uuid_clear(usr->thread);
    usr->private = calloc(1, sizeof(msg_t *));
    usr->subbed = calloc(1, sizeof(uuid_t));
    if (!usr->private || !usr->subbed)
        errx(84, "malloc failed");
    uuid_unparse_upper(usr->id, id);
    server_event_user_created(id, name);
}

user_t *register_new_user(server_t *srv, char *name)
{
    int i = 0;

    if (strlen(name) + 1 >= MAX_NAME_LENGTH)
        return (0);
    for (; srv->regs[i] != 0; i++);
    srv->regs = reallocarray(srv->regs, i + 2, sizeof(user_t *));
    if (!srv->regs)
        errx(84, "realloc failed");
    srv->regs[i] = malloc(sizeof(user_t));
    if (!srv->regs[i])
        errx(84, "malloc failed");
    srv->regs[i + 1] = 0;
    init_user(srv->regs[i], name);
    save_regs(srv->regs);
    return (srv->regs[i]);
}

void login(char *buf, conn_t *usr, server_t *srv)
{
    int i = 0;
    char **cmd = split_expect(buf, usr->fd, 2);

    if (!cmd)
        return;
    for (; srv->regs[i] &&
        strcmp(srv->regs[i]->username, cmd[1]); i++);
    if (srv->regs[i])
        usr->user = srv->regs[i];
    else
        usr->user = register_new_user(srv, cmd[1]);
    if (!usr->user)
        dprintf(usr->fd, MATR);
    else
        broad_login(srv, usr->user);
    free(cmd);
}

void logout(char *buf, conn_t *usr, server_t *srv)
{
    int fd = 0;

    if (!usr)
        return;
    fd = usr->fd;
    broad_logout(srv, usr->user);
    shutdown(fd, SHUT_RDWR);
    remove_client(usr, srv);
}
