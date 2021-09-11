/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui death broadcast
*/

#include "zappy.h"

int get_id(player_t *pl)
{
    int i = 0;

    while (pl->srv->players[i] && pl->srv->players[i] != pl)
        i++;
    return (i);
}

void broad_connect(player_t *pl)
{
    int id = get_id(pl);
    team_t *team = get_team_by_player(pl, pl->srv);
    struct timespec delay = ticks_to_spec(126 * 10, pl->srv);

    clock_gettime(CLOCK_REALTIME, &pl->death);
    add_spec(&pl->death, delay);
    for (int i = 0; pl->srv->guis[i]; i++) {
        write_player(pl->srv->guis[i], "pnw %d %d %d %d %d %s\n",
            id, pl->x, pl->y, pl->rotation, pl->vision,
            team->name);
    }
}

void broad_eject(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pex %d\n", id);
}

void broad_bcast(player_t *pl, char *msg)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pbc %d %s\n", id, msg);
}

void broad_death(player_t *pl)
{
    int id = get_id(pl);

    for (int i = 0; pl->srv->guis[i]; i++)
        write_player(pl->srv->guis[i], "pdi %d\n", id);
}
