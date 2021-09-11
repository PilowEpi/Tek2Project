/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** move commands
*/

#include <string.h>

#include "zappy.h"

void forward(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Forward")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(7, player, do_forward);
}

void right(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Right")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(7, player, do_right);
}

void left(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Left")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(7, player, do_left);
}
