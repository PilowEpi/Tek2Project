/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui item broadcasts
*/

#include "zappy.h"

void broad_set(player_t *pl, int type)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pdr %d %d\n", id, type);
    broad_inv(pl);
}

void broad_take(player_t *pl, int type)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pgt %d %d\n", id, type);
    broad_inv(pl);
}

void broad_inv(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pin %d %d %d %d %d %d %d %d %d %d\n",
            id, pl->x,
            pl->y, pl->food, pl->linemate, pl->deraumere, pl->sibur,
            pl->mendiane, pl->phiras, pl->thystame);
}
