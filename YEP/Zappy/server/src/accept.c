/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** connect clients
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <err.h>

#include "zappy.h"

void accept_client(int socket, server_t *srv)
{
    struct sockaddr_in clientname;
    socklen_t size = sizeof(clientname);
    int new = 0;
    player_t *pl = 0;

    pl = register_client(new, srv);
    if (!pl)
        return;
    new = accept(socket, (struct sockaddr *) &clientname, &size);
    if (new < 0) {
        rem((void **) srv->conns, pl);
        return;
    }
    FD_SET(new, &(srv->active));
    pl->buf->fd = new;
    write_player(pl, "WELCOME\n");
    srv->max_fd = srv->max_fd <= new ? new + 1 : srv->max_fd;
}

void remove_client(int fd, server_t *srv)
{
    player_t *pl = get_player_by_fd(fd, srv);
    team_t *te = get_team_by_player(pl, srv);

    FD_CLR (fd, &srv->active);
    rem((void **) srv->players, pl);
    rem((void **) srv->guis, pl);
    rem((void **) srv->conns, pl);
    if (te)
        rem((void **) te->players, pl);
    free(pl->buf->read);
    free(pl->buf->write);
    free(pl->buf);
    free(pl);
}

buf_t *get_buf_by_fd(int fd, server_t *srv)
{
    for (int i = 0; srv->conns[i]; i++) {
        if (fd == srv->conns[i]->buf->fd)
            return (srv->conns[i]->buf);
    }
    return (0);
}

player_t *get_player_by_fd(int fd, server_t *srv)
{
    for (int i = 0; srv->conns[i]; i++) {
        if (fd == srv->conns[i]->buf->fd)
            return (srv->conns[i]);
    }
    return (0);
}
