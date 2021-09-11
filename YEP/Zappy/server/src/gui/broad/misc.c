/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui death broadcast
*/

#include "zappy.h"

void broad_die(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pdi %d\n", id);
}
