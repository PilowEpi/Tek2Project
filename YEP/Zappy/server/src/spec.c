/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** spec computing
*/

#include "zappy.h"

struct timespec ticks_to_spec(int ticks, server_t *srv)
{
    int sec = ticks / srv->freq;
    double fsec = ticks / (double) srv->freq;
    long nsec = 1e9 * (fsec - sec);
    struct timespec spec = {.tv_sec = sec, .tv_nsec = nsec};

    return (spec);
}

int spec_to_ticks(struct timespec spec, server_t *srv)
{
    int ticks = 0;
    double nsec = spec.tv_nsec;

    nsec /= 1e9;
    nsec *= srv->freq;
    ticks += (int) (nsec);
    ticks += spec.tv_sec * srv->freq;
    return (ticks);
}
