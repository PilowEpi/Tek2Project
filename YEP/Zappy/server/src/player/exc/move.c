/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** env execution methods
*/

#include "zappy.h"

void move(player_t *player, int rot)
{
    switch (rot) {
    case 0:
        player->x++;
        player->x %= player->srv->width;
        break;
    case 1:
        player->y++;
        player->y %= player->srv->height;
        break;
    case 2:
        player->x = (player->x == 0 ?
            player->srv->width - 1 : player->x - 1);
        break;
    case 3:
        player->y = (player->y == 0 ?
            player->srv->height - 1 : player->y - 1);
        break;
    }
}

void do_forward(event_t *ev)
{
    move(ev->player, ev->player->rotation);
    write_player(ev->player, "ok\n");
    broad_fwd(ev->player);
}

void do_left(event_t *ev)
{
    ev->player->rotation++;
    ev->player->rotation %= 4;
    write_player(ev->player, "ok\n");
    broad_rotate(ev->player);
}

void do_right(event_t *ev)
{
    if (!ev->player->rotation)
        ev->player->rotation = 3;
    else
        ev->player->rotation--;
    write_player(ev->player, "ok\n");
    broad_rotate(ev->player);
}
