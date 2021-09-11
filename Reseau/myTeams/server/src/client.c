/*
** EPITECH PROJECT, 2021
** teams
** File description:
** client utils
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <err.h>

#include "server.h"

int create_socket(int port, server_t *srv)
{
    struct sockaddr_in addr;
    int sfd;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
        errx(84, "socket create error");
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
        errx(84, "setsockopt(SO_REUSEADDR) failed");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sfd, (struct sockaddr *) &addr,
        sizeof(struct sockaddr_in)) == -1)
        errx(84, "BIND error");
    if (listen(sfd, 3) != 0)
        errx(84, "LISTEN error");
    return (sfd);
}

void register_client(int fd, server_t *srv)
{
    int i = 0;

    for (; srv->conns[i] != 0; i++);
    srv->conns = reallocarray(srv->conns, i + 2, sizeof(conn_t *));
    if (!srv->conns)
        errx(84, "realloc failed");
    srv->conns[i] = malloc(sizeof(conn_t));
    if (!srv->conns[i])
        errx(84, "malloc failed");
    srv->conns[i + 1] = 0;
    srv->conns[i]->fd = fd;
    srv->conns[i]->user = 0;
    FD_SET (fd, &(srv->write));
}

void accept_client(int sock, server_t *srv)
{
    struct sockaddr_in clientname;
    socklen_t size = sizeof(clientname);
    int new = accept(sock, (struct sockaddr *) &clientname, &size);

    if (new < 0)
        errx(84, "accept fail");
    FD_SET(new, &(srv->active));
    register_client(new, srv);
    dprintf(new, "wesh\n");
}
