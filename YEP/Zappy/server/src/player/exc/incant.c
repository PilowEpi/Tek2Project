/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** incantation check
*/

#include "zappy.h"

int check_zone(secret_t *cur, player_t *pl)
{
    u128 tile = pl->srv->items[pl->y][pl->x];

    if (GET_ITEM_TYPE(tile, 1) >= cur->linemate  * cur->nb &&
        GET_ITEM_TYPE(tile, 2) >= cur->deraumere * cur->nb &&
        GET_ITEM_TYPE(tile, 3) >= cur->sibur     * cur->nb &&
        GET_ITEM_TYPE(tile, 4) >= cur->mendiane  * cur->nb &&
        GET_ITEM_TYPE(tile, 5) >= cur->phiras    * cur->nb &&
        GET_ITEM_TYPE(tile, 6) >= cur->thystame  * cur->nb)
        return (1);
    return (0);
}

void do_elevate(server_t *srv, player_t *pl)
{
    for (int i = 0; srv->players[i]; i++) {
        if (srv->players[i]->x != pl->x || srv->players[i]->y != pl->y)
            continue;
        srv->players[i]->vision++;
        broad_level(srv->players[i]);
    }
}

int incantation_check(server_t *srv, player_t *pl)
{
    int pl_chkd = 0;
    secret_t cur = secret[pl->vision - 1];

    for (int i = 0; srv->players[i]; i++) {
        if (srv->players[i]->x != pl->x || srv->players[i]->y != pl->y)
            continue;
        if (srv->players[i]->vision != pl->vision)
            return (0);
        pl_chkd++;
    }
    return (pl_chkd == cur.nb && check_zone(&cur, pl));
}
