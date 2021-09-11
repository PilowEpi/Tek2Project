/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** event utils
*/

#include <string.h>

#include "zappy.h"

event_t *create_event(uint16_t limit, player_t *player,
    void (*ptr)(event_t *))
{
    struct timespec to_add = ticks_to_spec(limit, player->srv);
    struct timespec delay = ticks(player);

    for (int i = 0; i < 10; i++) {
        if (!player->evs[i].status) {
            player->evs[i].status = 1;
            player->evs[i].player = player;
            player->evs[i].limit = limit;
            player->evs[i].exec = ptr;
            clock_gettime(CLOCK_REALTIME, &player->evs[i].date);
            add_spec(&player->evs[i].date, to_add);
            add_spec(&player->evs[i].date, delay);
            return (&player->evs[i]);
        }
    }
    return (0);
}

struct timespec get_closest_event_player(player_t *player)
{
    struct timespec found = {.tv_sec = 0, .tv_nsec = 0};

    for (int i = 0; i < 10; i++) {
        if (player->evs[i].status &&
            is_event_closer(&player->evs[i].date, &found))
            found = player->evs[i].date;
    }
    if (player->status == PLAYER &&
        is_event_closer(&player->death, &found))
        found = player->death;
    return (found);
}

void get_closest_event(server_t *srv, struct timespec **date,
    struct timespec *holder)
{
    struct timespec found = {.tv_sec = 0, .tv_nsec = 0};

    for (int i = 0; srv->conns[i]; i++) {
        found = get_closest_event_player(srv->conns[i]);
        if (found.tv_sec != 0 && !*date)
            *date = holder;
        if (is_event_closer(&found, *date))
            **date = found;
    }
    for (int i = 0; srv->s_evs[i]; i++) {
        if (!srv->s_evs[i]->status)
            continue;
        if (!*date)
            *date = holder;
        if (is_event_closer(&srv->s_evs[i]->date, *date))
            **date = srv->s_evs[i]->date;
    }
}

void get_next_event(server_t *srv, struct timespec **date)
{
    static struct timespec *holder = 0;
    struct timespec found = {.tv_sec = 0, .tv_nsec = 0};

    *date = 0;
    if (!*date && !holder) {
        holder = malloc(sizeof(struct timespec));
        if (!holder)
            return;
    }
    holder->tv_sec = 0;
    holder->tv_nsec = 0;
    get_closest_event(srv, date, holder);
    if (*date)
        to_delay(*date);
}
