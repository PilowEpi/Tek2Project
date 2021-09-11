/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** args handling
*/

#include <string.h>
#include <stdlib.h>

#include "zappy.h"

int handle4(int *idx, int ac, char **av, server_t *server)
{
    if (!strcmp(av[*idx], "-f")) {
        (*idx)++;
        if (*idx >= ac || !is_numeric(av[*idx]))
            return (1);
        server->freq = atoi(av[*idx]);
        return (0);
    }
    return (1);
}

int handle3(int *idx, int ac, char **av, server_t *server)
{
    if (!strcmp(av[*idx], "-y")) {
        (*idx)++;
        if (*idx >= ac || !is_numeric(av[*idx]))
            return (1);
        server->height = atoi(av[*idx]);
        return (0);
    }
    if (!strcmp(av[*idx], "-c")) {
        (*idx)++;
        if (*idx >= ac || !is_numeric(av[*idx]))
            return (1);
        server->max_cli = atoi(av[*idx]);
        return (0);
    }
    return handle4(idx, ac, av, server);
}

int handle2(int *idx, int ac, char **av, server_t *server)
{
    if (!strcmp(av[*idx], "-p")) {
        (*idx)++;
        if (*idx >= ac || !is_numeric(av[*idx]))
            return (1);
        server->port = atoi(av[*idx]);
        return (0);
    }
    if (!strcmp(av[*idx], "-x")) {
        (*idx)++;
        if (*idx >= ac || !is_numeric(av[*idx]))
            return (1);
        server->width = atoi(av[*idx]);
        return (0);
    }
    return handle3(idx, ac, av, server);
}
