/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** init map
*/

#include <err.h>
#include <string.h>

#include "zappy.h"

void place_item(server_t *srv, int type)
{
    int round = 5;
    int x = rand() % srv->width;
    int y = rand() % srv->height;

    while (round--) {
        if (srv->items[y][x].a || srv->items[y][x].a) {
            x = rand() % srv->width;
            y = rand() % srv->height;
            continue;
        }
        break;
    }
    ADD_ITEM_TYPE(srv->items[y][x], type, 1);
    broad_place(srv, x, y);
}

void alloc_map(server_t *srv)
{
    srv->items = malloc(sizeof(u128 *) * srv->height);
    if (!srv->items)
        errx(84, "malloc");
    for (int i = 0; i < srv->height; i++) {
        srv->items[i] = malloc(sizeof(u128) * srv->width);
        if (!srv->items[i])
            errx(84, "malloc");
        memset(srv->items[i], 0, sizeof(u128) * srv->width);
    }
}

int get_qty(server_t *srv, int type)
{
    int qty = 0;

    for (int i = 0; i < srv->height; i++) {
        for (int j = 0; j < srv->width; j++)
            qty += (GET_ITEM_TYPE(srv->items[i][j], type));
    }
    return (qty);
}

void fill_map(server_t *srv)
{
    double qty = 0;
    int cur_qty = 0;

    for (int i = 0; i < 7; i++) {
        qty = srv->width * srv->height * item_density[i];
        cur_qty = get_qty(srv, i);
        while (cur_qty++ < (int) qty)
            place_item(srv, i);
    }
}
