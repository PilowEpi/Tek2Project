/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** server struct init
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#include "zappy.h"

void init_arrays(server_t *server)
{
    server->players = malloc(sizeof(player_t *));
    server->conns = malloc(sizeof(player_t *));
    server->guis = malloc(sizeof(player_t *));
    server->s_evs = malloc(sizeof(event_t *) * 21);
    if (!server->players || !server->conns ||
        !server->guis || !server->s_evs)
        errx(84, "malloc");
    server->players[0] = 0;
    server->conns[0] = 0;
    server->guis[0] = 0;
    memset(server->s_evs, 0, sizeof(event_t *) * 21);
    for (int i = 0; i < 20; i++) {
        server->s_evs[i] = malloc(sizeof(event_t));
        if (!server->s_evs[i])
            errx(84, "malloc");
        memset(server->s_evs[i], 0, sizeof(event_t));
    }
}

server_t *init_server(void)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        errx(84, "malloc");
    server->freq = 100;
    server->port = 4242;
    server->width = 10;
    server->height = 10;
    server->max_cli = 3;
    server->teams = 0;
    server->items = 0;
    server->max_fd = 3;
    init_arrays(server);
    return (server);
}

char **get_teams(int *i, int ac, char **av, server_t *server)
{
    char **teams = malloc(sizeof(char *));
    char *holder = 0;

    teams[0] = 0;
    for ((*i)++; *i < ac && av[(*i)][0] != '-'; (*i)++) {
        holder = strdup(av[*i]);
        if (!holder)
            errx(84, "malloc");
        if (append((void ***) &teams, holder))
            errx(84, "append");
    }
    (*i)--;
    return (teams);
}

int handle_args(int ac, char **av, server_t *server)
{
    char **teams = 0;

    for (int i = 1; i < ac; i++) {
        if (!strcmp(av[i], "-help")) {
            puts(USAGE);
            return (1);
        }
        if (!strcmp(av[i], "-n")) {
            teams = get_teams(&i, ac, av, server);
            continue;
        }
        if (handle2(&i, ac, av, server)) {
            puts(USAGE);
            return (85);
        }
    }
    create_teams(teams, server);
    alloc_map(server);
    fill_map(server);
    return (0);
}
