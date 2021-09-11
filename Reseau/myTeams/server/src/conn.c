/*
** EPITECH PROJECT, 2021
** teams
** File description:
** connection utils
*/

#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

#include "server.h"

int is_user_connected(uuid_t id, server_t *srv)
{
    for (int i = 0; srv->conns[i]; i++) {
        if (!uuid_compare(srv->conns[i]->user->id, id))
            return (1);
    }
    return (0);
}

conn_t *get_user_fd(server_t *srv, int fd)
{
    for (int i = 0; srv->conns[i] != 0; i++)
        if (srv->conns[i]->fd == fd)
            return (srv->conns[i]);
    return (0);
}

void remove_client(conn_t *usr, server_t *srv)
{
    int passed = 0;
    int fd = usr->fd;

    free(usr);
    for (int i = 0; srv->conns[i] != 0; i++) {
        if (srv->conns[i] == usr)
            passed = 1;
        if (!passed)
            continue;
        srv->conns[i] = srv->conns[i + 1];
    }
    FD_CLR (fd, &(srv->active));
    FD_CLR (fd, &(srv->write));
    close(fd);
}

void remove_client_fd(int fd, server_t *srv)
{
    conn_t *usr = get_user_fd(srv, fd);

    remove_client(usr, srv);
}
