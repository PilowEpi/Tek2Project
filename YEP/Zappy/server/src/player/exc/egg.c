/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** egg hatching
*/

#include "zappy.h"

void do_hatch(event_t *ev)
{
    team_t *team = get_team_by_player(ev->player, ev->player->srv);
    u128 *egg = malloc(sizeof(u128));
    uint64_t coord = (uint64_t) ev->msg;

    if (!egg || append((void ***) &team->eggs, egg))
        return;
    egg->a = team->egg_id++;
    egg->b = coord;
    team->size_left++;
    broad_hatch(ev->player, ev->type);
}
