/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** teams getter
*/

#include <string.h>

#include "zappy.h"

team_t *get_team_by_name(char *name, server_t *srv)
{
    for (int i = 0; srv->teams[i]; i++) {
        if (!strcmp(srv->teams[i]->name, name))
            return (srv->teams[i]);
    }
    return (0);
}

int is_player_in_team(player_t *player, team_t *team)
{
    for (int i = 0; team->players[i]; i++) {
        if (team->players[i] == player)
            return (1);
    }
    return (0);
}

team_t *get_team_by_player(player_t *player, server_t *srv)
{
    for (int i = 0; srv->teams[i]; i++) {
        if (is_player_in_team(player, srv->teams[i]))
            return (srv->teams[i]);
    }
    return (0);
}
