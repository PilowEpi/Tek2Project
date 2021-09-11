/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui incantation broadcast
*/

#include "zappy.h"

void write_casters(player_t *pl, player_t *gui)
{
    secret_t cur = secret[pl->vision];
    server_t *srv = pl->srv;

    for (int i = 0; pl->srv->players[i]; i++) {
        if (srv->players[i]->x != pl->x || srv->players[i]->y != pl->y
            || srv->players[i]->vision != pl->vision)
            continue;
        write_player(gui, " %d", get_id(pl->srv->players[i]));
    }
}

void broad_istart(player_t *pl)
{
    for (int i = 0; pl->srv->guis[i]; i++) {
        write_player(pl->srv->guis[i], "pic %d %d %d", pl->x, pl->y,
            pl->vision);
        write_casters(pl, pl->srv->guis[i]);
        write_player(pl->srv->guis[i], "\n");
    }
}

void broad_iend(player_t *pl, int res)
{
    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pie %d %d %d\n",
            pl->x, pl->y, res);
}

void broad_level(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "plv %d %d\n",
            id, pl->vision);
}
