/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui map broadcasts
*/

#include "zappy.h"

void broad_place(server_t *srv, int x, int y)
{
    u128 tile = srv->items[y][x];

    for (int i = 0; srv->guis[i]; i++) {
        write_player(srv->guis[i], "bct %d %d", x, y);
        for (int j = 0; j < 7; j++)
            write_player(srv->guis[i], " %d", GET_ITEM_TYPE(tile, j));
        write_player(srv->guis[i], "\n");
    }
}

void send_players(player_t *gui)
{
    int id = 0;
    team_t *team = 0;
    player_t *pl = 0;

    for (int i = 0; gui->srv->players[i]; i++) {
        pl = gui->srv->players[i];
        team = get_team_by_player(pl, gui->srv);
        write_player(gui, "pnw %d %d %d %d %d %s\n",
            get_id(pl), pl->x, pl->y, pl->rotation, pl->vision,
            team->name);
    }
}
