/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** register client
*/

#include <stdlib.h>
#include <string.h>

#include "zappy.h"

int init_buf(buf_t *buf, int fd)
{
    buf->read = malloc(512);
    buf->write = malloc(512);
    if (!buf->read || !buf->write) {
        free(buf->read);
        free(buf->write);
        return (1);
    }
    memset(buf->read, 0, 512);
    memset(buf->write, 0, 512);
    buf->r_buf_size = 512;
    buf->w_buf_size = 512;
    buf->fd = fd;
    return (0);
}

void set_player_coord(player_t *player)
{
    team_t *team = get_team_by_player(player, player->srv);
    u128 *egg = 0;

    if (!team)
        return;
    for (int i = 0; team->eggs[i]; i++) {
        if (team->egg_match != team->eggs[i]->a)
            continue;
        egg = team->eggs[i];
        rem((void **) team->eggs, team->eggs[i]);
        break;
    }
    if (!egg)
        return;
    player->x = (egg->b & 0xFFFFFFFF);
    player->y = (egg->b >> 32);
    free(egg);
}

int init_player(player_t *player, buf_t *buf, server_t *srv)
{
    memset(player, 0, sizeof(player_t));
    player->status = PENDING;
    player->buf = buf;
    player->vision = 1;
    player->rotation = rand() % 4;
    player->x = rand() % srv->width;
    player->y = rand() % srv->height;
    player->srv = srv;
    player->food = 10;
    return (0);
}

player_t *register_client(int fd, server_t *srv)
{
    buf_t *buf = malloc(sizeof(buf_t));
    player_t *player = malloc(sizeof(player_t));

    if (!buf || !player ||
        append((void ***) &srv->conns, player) ||
        init_buf(buf, fd) || init_player(player, buf, srv)) {
        free(buf);
        free(player);
        rem((void **) srv->conns, player);
        return (0);
    }
    return (player);
}
