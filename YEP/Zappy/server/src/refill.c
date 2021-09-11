/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** refill map
*/

#include "zappy.h"

void do_refill(server_t *srv)
{
    int ticks = 0;
    int old = 0;
    struct timespec now;
    struct timespec cpy;

    clock_gettime(CLOCK_REALTIME, &now);
    for (int i = 0; srv->players[i]; i++) {
        cpy = srv->players[i]->death;
        delay(&cpy, &now);
        ticks = spec_to_ticks(cpy, srv);
        old = srv->players[i]->food;
        srv->players[i]->food = ticks / 126;
    }
}

void set_food(server_t *srv)
{
    static struct timespec delayer = {0};
    struct timespec ticks = ticks_to_spec(20, srv);
    struct timespec now;

    clock_gettime(CLOCK_REALTIME, &now);
    if (delayer.tv_sec &&
        !is_event_closer(&delayer, &now))
        return;
    delayer = now;
    add_spec(&delayer, ticks);
    do_refill(srv);
}
