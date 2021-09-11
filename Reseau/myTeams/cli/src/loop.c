/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cli loop
*/

#include <sys/select.h>
#include <unistd.h>
#include <stdio.h>
#include <err.h>

#include "cli.h"

int read_cli(int socket)
{
    char *line = 0;
    size_t len = 0;
    ssize_t read;

    if ((read = getline(&line, &len, stdin)) != -1)
        parse(line, socket);
    else
        return (-1);
    return (0);
}

int read_server(int socket)
{
    char buffer[1024] = {0};
    int nbytes;

    nbytes = read(socket, buffer, 1024);
    if (nbytes < 0)
        errx(84, "read socket fail");
    else if (nbytes == 0)
        return (-1);
    else
        forward_logger(buffer);
    return (0);
}

int handle_set(fd_set *read, int socket)
{
    if (FD_ISSET(socket, read)) {
        if (read_server(socket))
            return (1);
        FD_CLR(socket, read);
    } else if (FD_ISSET(0, read)) {
        return (read_cli(socket));
    }
    return (0);
}

void loop(int socket)
{
    fd_set active;
    fd_set read;

    FD_ZERO (&active);
    FD_SET (socket, &active);
    FD_SET (0, &active);
    while (1) {
        read = active;
        if (select(FD_SETSIZE, &read, 0, 0, 0) < 0)
            errx(84, "select error\n");
        if (handle_set(&read, socket))
            break;
    }
}
