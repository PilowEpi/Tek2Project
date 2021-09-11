/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui map commands
*/

#include <string.h>

#include "zappy.h"

void msz(char *un, player_t *gui)
{
    (void) un;
    write_player(gui, "msz %d %d\n",
        gui->srv->width, gui->srv->height);
}

void write_tile(int x, int y, player_t *gui)
{
    u128 tile = gui->srv->items[y][x];

    write_player(gui, "bct %d %d", x, y);
    for (int i = 0; i < 7; i++)
        write_player(gui, " %d", GET_ITEM_TYPE(tile, i));
    write_player(gui, "\n");
}

void bct(char *cmd, player_t *gui)
{
    char *par1 = strchr(cmd, ' ') + 1;
    char *par2 = strchr(par1, ' ') + 1;
    int x = atoi(par1);
    int y = atoi(par2);

    write_tile(x, y, gui);
}

void mct(char *cmd, player_t *gui)
{
    for (int i = 0; i < gui->srv->width; i++) {
        for (int j = 0; j < gui->srv->height; j++)
            write_tile(i, j, gui);
    }
}
