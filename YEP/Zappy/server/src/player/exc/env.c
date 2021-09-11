/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** env exec methods
*/

#include <string.h>

#include "zappy.h"

void do_look(event_t *ev)
{
    write_player(ev->player, "[ ");
    for (int i = 0; i < ev->player->vision + 1; i++) {
        for (int j = 0; j < i * 2 + 1; j++) {
            print_at(ev->player, i, j);
            write_player(ev->player, i == ev->player->vision &&
                j == i * 2 ? "" : ", ");
        }
    }
    write_player(ev->player, "]\n");
}

void do_take(event_t *ev)
{
    int type = ev->type;
    player_t *pl = ev->player;
    u128 *pos = pl->srv->items[pl->y];

    if (type == 33 || !GET_ITEM_TYPE(pos[pl->x], type)) {
        write_player(ev->player, "ko\n");
        return;
    }
    add_to_inventory(type, pl, 1);
    REM_ITEM_TYPE(pos[pl->x], type, 1);
    write_player(ev->player, "ok\n");
    broad_take(ev->player, type);
}

void do_set(event_t *ev)
{
    int type = ev->type;
    player_t *pl = ev->player;
    u128 *pos = pl->srv->items[pl->y];

    if (type < 0 || !get_from_inventory(type, pl)) {
        write_player(ev->player, "ko\n");
        return;
    }
    rem_from_inventory(type, pl, 1);
    ADD_ITEM_TYPE(pos[pl->x], type, 1);
    write_player(ev->player, "ok\n");
    broad_set(ev->player, type);
}

void do_eject(event_t *ev)
{
    int x = ev->player->x;
    int y = ev->player->y;
    server_t *srv = ev->player->srv;

    for (int i = 0; srv->players[i]; i++) {
        if (srv->players[i]->x != x || srv->players[i]->y != y)
            continue;
        move(srv->players[i], ev->player->rotation);
        write_player(ev->player, "Eject: %d\n", 1);
    }
    write_player(ev->player, "ok\n");
    broad_eject(ev->player);
}

void do_ko(event_t *ev)
{
    write_player(ev->player, "ko\n");
}
