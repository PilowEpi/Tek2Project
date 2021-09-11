/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** teams struct init
*/

#include <err.h>

#include "zappy.h"

void init_team(char *name, team_t *team, server_t *server)
{
    team->size_left = server->max_cli;
    team->name = name;
    team->egg_id = 0;
    team->egg_match = 0;
    team->players = malloc(sizeof(player_t *));
    team->eggs = malloc(sizeof(u128 *));
    if (!team->players || !team->eggs)
        errx(84, "malloc");
    team->players[0] = 0;
    team->eggs[0] = 0;
}

void create_teams(char **names, server_t *server)
{
    team_t *holder;

    server->teams = malloc(sizeof(team_t *));
    if (!server->teams)
        errx(84, "malloc");
    server->teams[0] = 0;
    for (int i = 0; names && names[i]; i++) {
        holder = malloc(sizeof(team_t));
        if (!holder)
            errx(84, "malloc");
        init_team(names[i], holder, server);
        if (append((void ***) &server->teams, holder))
            errx(84, "append");
    }
    free(names);
}

