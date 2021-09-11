/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui egg broadcast
*/

#include "zappy.h"

void broad_egg(player_t *pl, int egg_id)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "enw %d %d %d %d\n",
            egg_id, id, pl->x, pl->y);
}

void broad_hatch(player_t *pl, int egg_id)
{
    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "eht %d\n",
            egg_id);
}
