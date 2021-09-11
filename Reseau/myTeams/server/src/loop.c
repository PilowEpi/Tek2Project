/*
** EPITECH PROJECT, 2021
** teams
** File description:
** main loop
*/

#include <err.h>
#include <unistd.h>

#include "server.h"

int read_client(int filedes, server_t *srv)
{
    char buffer[1024] = {0};
    int nbytes;

    nbytes = read(filedes, buffer, 1024);
    if (nbytes < 0)
        return (-1);
    else if (nbytes == 0)
        return (-1);
    else
        parse_msg(filedes, buffer, srv);
    return (0);
}

void service_fd(int server, int fd, server_t *srv)
{
    if (fd == server) {
        accept_client(server, srv);
    } else {
        if (read_client(fd, srv))
            remove_client_fd(fd, srv);
    }
}

void handle_set(int server, server_t *srv)
{
    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &(srv->read))) {
            service_fd(server, i, srv);
        }
    }
}

void loop(int socket, server_t *srv)
{
    FD_ZERO (&srv->active);
    FD_SET (socket, &(srv->active));
    while (1) {
        srv->read = srv->active;
        if (select(FD_SETSIZE, &(srv->read), &(srv->write), 0, 0) < 0)
            errx(84, "select error\n");
        handle_set(socket, srv);
    }
}
