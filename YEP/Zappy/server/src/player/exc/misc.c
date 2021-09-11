/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** misc execution methods
*/

#include <string.h>

#include "zappy.h"

void do_inventory(event_t *ev)
{
    write_player(ev->player, "[ food %d, linemate %d, deraumere %d"
        ", sibur %d, mendiane %d, phiras %d, thystame %d ]\n",
        ev->player->food, ev->player->linemate, ev->player->deraumere,
        ev->player->sibur, ev->player->mendiane, ev->player->phiras,
        ev->player->thystame);
}

void do_broadcast(event_t *ev)
{
    int size_x = ev->player->srv->width;
    int size_y = ev->player->srv->height;
    char *msg = ev->msg;
    int cel = 0;

    write_player(ev->player, msg ? "ok\n" : "ko\n");
    if (!msg)
        return;
    for (int i = 0; ev->player->srv->players[i]; i++) {
        if (ev->player->srv->players[i] == ev->player)
            continue;
        cel = case_id(ev->player, ev->player->srv->players[i], size_x, size_y);
        write_player(ev->player->srv->players[i], "message %d, %s\n", cel, msg);
    }
    broad_bcast(ev->player, msg);
    free(msg);
}

void do_xfork(event_t *ev)
{
    static uint64_t egg_id = 0;
    event_t *event = create_server_event(600, ev->player->srv, do_hatch);
    uint64_t coord = (ev->player->x | ((uint64_t) ev->player->y << 32));

    write_player(ev->player, event ? "ok\n" : "ko\n");
    if (event) {
        event->type = egg_id++;
        event->player = ev->player;
        event->msg = (char *) coord;
    }
    broad_egg(ev->player, event->type);
}

void do_incantation(event_t *ev)
{
    if (incantation_check(ev->player->srv, ev->player)) {
        do_elevate(ev->player->srv, ev->player);
        write_player(ev->player, "Current level: %d\n", ev->player->vision);
        broad_iend(ev->player, 1);
    } else {
        write_player(ev->player, "ko\n");
        broad_iend(ev->player, 0);
    }
}
