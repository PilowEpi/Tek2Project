/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui move broadcast
*/

#include "zappy.h"

void broad_fwd(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "ppf %d %d %d\n", id, pl->x, pl->y);
}

void broad_rotate(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "ppr %d %d\n", id, pl->rotation);
}
