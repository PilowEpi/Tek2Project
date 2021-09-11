/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** gui player commands
*/

#include <string.h>

#include "zappy.h"

void tna(char *cmd, player_t *gui)
{
    for (int i = 0; gui->srv->teams[i]; i++)
        write_player(gui, "tna %s\n", gui->srv->teams[i]->name);
    send_players(gui);
}

void ppo(char *cmd, player_t *gui)
{
    char *par1 = strchr(cmd, ' ') + 1;
    int n = atoi(par1);
    int len = 0;
    player_t *pl = 0;

    while (gui->srv->players[len])
        len++;
    if (n >= len)
        return;
    pl = gui->srv->players[n];
    write_player(gui, "ppo %d %d %d %d\n", n, pl->x, pl->y,
        pl->rotation);
}

void plv(char *cmd, player_t *gui)
{
    char *par1 = strchr(cmd, ' ') + 1;
    int n = atoi(par1);
    int len = 0;
    player_t *pl = 0;

    while (gui->srv->players[len])
        len++;
    if (n >= len)
        return;
    pl = gui->srv->players[n];
    write_player(gui, "plv %d %d\n", n, pl->vision);
}

void pin(char *cmd, player_t *gui)
{
    char *par1 = strchr(cmd, ' ') + 1;
    int n = atoi(par1);
    int len = 0;
    player_t *pl = 0;

    while (gui->srv->players[len])
        len++;
    if (n >= len)
        return;
    pl = gui->srv->players[n];
    write_player(gui, "pin %d %d %d %d %d %d %d %d %d %d\n", n, pl->x,
        pl->y, pl->food, pl->linemate, pl->deraumere, pl->sibur,
        pl->mendiane, pl->phiras, pl->thystame);
}
