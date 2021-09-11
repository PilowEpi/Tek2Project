/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** env commands
*/

#include <string.h>

#include "zappy.h"

void look(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Look")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(7, player, do_look);
}

void take(char *cmd, player_t *player)
{
    event_t *ev = create_event(7, player, do_take);
    int type = item_to_enum(strchr(cmd, ' ') + 1);

    if (!ev)
        return;
    if (type < 0)
        ev->type = 33;
    else
        ev->type = (uint8_t) type;
}

void set(char *cmd, player_t *player)
{
    event_t *ev = create_event(7, player, do_set);
    int type = item_to_enum(strchr(cmd, ' ') + 1);

    if (!ev)
        return;
    if (type < 0)
        ev->type = 33;
    else
        ev->type = (uint8_t) type;
}

void eject(char *cmd, player_t *player)
{
    if (strcmp(cmd, "Eject")) {
        write_player(player, "ko\n");
        return;
    }
    create_event(7, player, do_eject);
}
