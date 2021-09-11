/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** time computing
*/

#include <time.h>

#include "zappy.h"

struct timespec ticks(player_t *pl)
{
    struct timespec ticks = {.tv_sec = 0, .tv_nsec = 0};
    struct timespec cpy = {.tv_sec = 0, .tv_nsec = 0};
    struct timespec holder;
    struct timespec now;

    clock_gettime(CLOCK_REALTIME, &now);
    holder = now;
    for (int i = 0; i < 10; i++) {
        if (!pl->evs[i].status)
            continue;
        cpy = pl->evs[i].date;
        if (!is_event_closer(&cpy, &holder))
            holder = cpy;
    }
    delay(&holder, &now);
    add_spec(&ticks, holder);
    return (ticks);
}

void add_spec(struct timespec *t1, struct timespec t2)
{
    t1->tv_sec += t2.tv_sec;
    t1->tv_nsec += t2.tv_nsec;
    if (t1->tv_nsec >= 1e9) {
        t1->tv_nsec -= 1e9;
        t1->tv_sec++;
    }
}

int is_event_closer(struct timespec *d1, struct timespec *d2)
{
    if (d1->tv_sec == 0 || d2->tv_sec == 0)
        return (d1->tv_sec == 0 ? 0 : 1);
    if (d1->tv_sec == d2->tv_sec)
        return (d1->tv_nsec < d2->tv_nsec);
    return (d1->tv_sec < d2->tv_sec);
}

void delay(struct timespec *d1, struct timespec *d2)
{
    if (d1->tv_nsec < d2->tv_nsec) {
        d1->tv_sec = d1->tv_sec - d2->tv_sec - 1;
        d1->tv_nsec = d1->tv_nsec - d2->tv_nsec + 1000000000UL;
    } else {
        d1->tv_sec = d1->tv_sec - d2->tv_sec;
        d1->tv_nsec = d1->tv_nsec - d2->tv_nsec;
    }
}

void to_delay(struct timespec *date)
{
    struct timespec now;

    clock_gettime(CLOCK_REALTIME, &now);
    delay(date, &now);
    date->tv_nsec /= 1000;
    date->tv_sec = date->tv_sec < 0 ? 0 : date->tv_sec;
    date->tv_nsec = date->tv_nsec < 0 ? 0 : date->tv_nsec;
}
