/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui time commands
*/

#include <string.h>

#include "zappy.h"

void sgt(char *cmd, player_t *gui)
{
    write_player(gui, "sgt %d\n", gui->srv->freq);
}

void sst(char *cmd, player_t *gui)
{
    char *par1 = strchr(cmd, ' ') + 1;
    int n = atoi(par1);

    if (n <= 0)
        return;
    gui->srv->freq = n;
    write_player(gui, "sst %d\n", gui->srv->freq);
}
