/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** command parsing
*/

#include <stdio.h>
#include <string.h>

#include "zappy.h"

void reg_gui(player_t *player, server_t *srv)
{
    player->status = GUI;
    append((void ***) &srv->guis, player);
    write_player(player, "ok\n");
}

void handle_pending(char *cmd, player_t *player, server_t *srv)
{
    team_t *team = get_team_by_name(cmd, srv);

    if (!strcmp(cmd, GUI_MAGIC)) {
        reg_gui(player, srv);
        return;
    }
    if (!team || !team->size_left) {
        write_player(player, "ko\n");
        return;
    }
    player->status = PLAYER;
    append((void ***) &team->players, player);
    append((void ***) &srv->players, player);
    team->size_left--;
    set_player_coord(player);
    write_player(player, "%d\n%d %d\n",
        team->size_left, srv->width, srv->height);
    broad_connect(player);
}

void handle_player(char *cmd, player_t *player, server_t *srv)
{
    char *cmds[] = {"Forward", "Right", "Left", "Look", "Inventory",
        "Broadcast ", "Connect_nbr", "Fork", "Eject", "Take ",
        "Set ", "Incantation", 0};
    void (*fnts[])(char *, player_t *) = {forward, right,
        left, look, inventory, broadcast, connect_nb, xfork, eject,
        take, set, incantation, 0};
    size_t i = 0;

    for (; cmds[i] != 0; i++)
        if (!strncmp(cmds[i], cmd, strlen(cmds[i])))
            break;
    if (player && cmds[i])
        fnts[i](cmd, player);
    else
        create_event(7, player, do_ko);
}

void handle_gui(char *cmd, player_t *player, server_t *srv)
{
    char *cmds[] = {"msz", "bct", "mct", "tna", "ppo",
        "plv ", "pin", "sgt", "sst", 0};
    void (*fnts[])(char *, player_t *) = {msz, bct, mct, tna, ppo,
        plv, pin, sgt, sst, 0};
    size_t i = 0;

    for (; cmds[i] != 0; i++)
        if (!strncmp(cmds[i], cmd, strlen(cmds[i])))
            break;
    if (player && cmds[i])
        fnts[i](cmd, player);
    else
        write_player(player, "ko\n");
}

void flush_input(char *cmd, buf_t *buf, server_t *srv)
{
    player_t *player = get_player_by_fd(buf->fd, srv);

    *(strchr(cmd, '\n')) = 0;
    puts(cmd);
    switch (player->status) {
    case PENDING:
        handle_pending(cmd, player, srv);
        break;
    case PLAYER:
        handle_player(cmd, player, srv);
        break;
    case GUI:
        handle_gui(cmd, player, srv);
        break;
    }
}
