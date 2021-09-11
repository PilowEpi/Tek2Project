/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** misc commands
*/

#include <string.h>

#include "zappy.h"

void inventory(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Inventory")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(1, player, do_inventory);
}

void broadcast(char *cmd, player_t *player)
{
    event_t *ev = create_event(7, player, do_broadcast);

    if (ev)
        ev->msg = strdup(strchr(cmd, ' ') + 1);
}

void connect_nb(char *cmd, player_t *player)
{
    team_t *team = get_team_by_player(player, player->srv);

    if (strcmp(cmd, "Connect_nbr")) {
        write_player(player, "ko\n");
        return;
    }
    write_player(player, "%d\n", team->size_left);
}

void xfork(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Fork")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(42, player, do_xfork);
}

void incantation(char *cmd, player_t *player)
{
    if (incantation_check(player->srv, player)) {
        write_player(player, "Elevation underway\n");
        broad_istart(player);
        create_event(300, player, do_incantation);
    } else {
        write_player(player, "ko\n");
    }
}
