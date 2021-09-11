/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** item utils
*/

#include <string.h>

#include "zappy.h"

int item_to_enum(char *item)
{
    char *names[] = {"food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame", 0};

    int i = 0;
    for (; names[i] != 0; i++)
        if (!strncmp(names[i], item, strlen(names[i])))
            break;
    if (!names)
        return (-1);
    return (i);
}

int get_from_inventory(int type, player_t *player)
{
    switch (type) {
    case FOOD:
        return player->food;
    case LINEMATE:
        return player->linemate;
    case DERAUMERE:
        return player->deraumere;
    case SIBUR:
        return player->sibur;
    case MENDIANE:
        return player->mendiane;
    case PHIRAS:
        return player->phiras;
    case THYSTAME:
        return player->thystame;
    }
    return (-1);
}

void rem_from_inventory(int type, player_t *player, int qty)
{
    add_to_inventory(type, player, -qty);
}

void handle_food(player_t *pl, int qty)
{
    struct timespec t_delay = ticks_to_spec(126, pl->srv);

    if (qty > 0)
        add_spec(&pl->death, t_delay);
    else
        delay(&pl->death, &t_delay);
}

void add_to_inventory(int type, player_t *player, int qty)
{
    switch (type) {
    case FOOD: player->food += qty;
        handle_food(player, qty);
        break;
    case LINEMATE: player->linemate += qty;
        break;
    case DERAUMERE: player->deraumere += qty;
        break;
    case SIBUR: player->sibur += qty;
        break;
    case MENDIANE: player->mendiane += qty;
        break;
    case PHIRAS: player->phiras += qty;
        break;
    case THYSTAME: player->thystame += qty;
        break;
    }
}
