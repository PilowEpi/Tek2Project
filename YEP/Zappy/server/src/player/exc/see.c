/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** look command
*/

#include "zappy.h"

void print_type(buf_t *buf, int type)
{
    switch (type) {
    case FOOD: write_buf(buf, "food");
        break;
    case LINEMATE: write_buf(buf, "linemate");
        break;
    case DERAUMERE: write_buf(buf, "deraumere");
        break;
    case SIBUR: write_buf(buf, "sibur");
        break;
    case MENDIANE: write_buf(buf, "mendiane");
        break;
    case PHIRAS: write_buf(buf, "phiras");
        break;
    case THYSTAME: write_buf(buf, "thystame");
        break;
    default: return;
    }
}

void print_xy(server_t *srv, buf_t *buf, int x, int y)
{
    uint8_t type = 0;
    uint8_t init = 0;

    for (int i = 0; srv->players[i]; i++) {
        if (srv->players[i]->x == x && srv->players[i]->y == y) {
            write_buf(buf, init ? " " : "");
            write_buf(buf, "player");
            init = 1;
        }
    }
    for (int i = 0; i < 7; i++) {
        type = GET_ITEM_TYPE(srv->items[y][x], i);
        for (int j = 0; j < type; j++) {
            write_buf(buf, init ? " " : "");
            print_type(buf, i);
            init = 1;
        }
    }
}

int get_pos(int val, int sub, int add, int max)
{
    sub %= max;
    add %= max;
    if (sub > val)
        val += max - sub;
    else
        val -= sub;
    val += add;
    val %= max;
    return (val);
}

void print_at(player_t *pl, int i, int j)
{
    switch (pl->rotation) {
    case 0:
        print_xy(pl->srv, pl->buf, get_pos(pl->x, 0, i, pl->srv->width),
            get_pos(pl->y, j, i, pl->srv->height));
        break;
    case 1:
        print_xy(pl->srv, pl->buf, get_pos(pl->x, i, j, pl->srv->width),
            get_pos(pl->y, 0, i, pl->srv->height));
        break;
    case 2:
        print_xy(pl->srv, pl->buf, get_pos(pl->x, i, 0, pl->srv->width),
            get_pos(pl->y, i, j, pl->srv->height));
        break;
    case 3:
        print_xy(pl->srv, pl->buf, get_pos(pl->x, j, i, pl->srv->width),
            get_pos(pl->y, i, 0, pl->srv->height));
        break;
    }
}
