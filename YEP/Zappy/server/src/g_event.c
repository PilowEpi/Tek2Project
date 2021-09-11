/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** server global events
*/

#include <string.h>

#include "zappy.h"

event_t *find_server_slot(server_t *srv)
{
    for (int i = 0; srv->s_evs[i]; i++) {
        if (!srv->s_evs[i]->status)
            return (srv->s_evs[i]);
    }
    return (0);
}

void enlarge_ev_slots(server_t *srv)
{
    event_t *ptr = 0;
    size_t count = 0;
    size_t n = 0;
    event_t **holder = 0;

    for (; srv->s_evs[n] != 0; n++);
    holder = reallocarray(srv->s_evs, n + 11, sizeof(event_t *));
    if (!holder)
        return;
    srv->s_evs = holder;
    for (int i = 0; i < 11; i++)
        srv->s_evs[n + i] = 0;
    while (count++ < 10) {
        ptr = malloc(sizeof(event_t));
        if (!ptr)
            return;
        memset(ptr, 0, sizeof(event_t));
        srv->s_evs[n + count - 1] = ptr;
    }
}

event_t *create_server_event(uint16_t limit, server_t *srv,
    void (*ptr)(event_t *))
{
    event_t *found = find_server_slot(srv);
    struct timespec to_add = ticks_to_spec(limit, srv);

    if (!found) {
        enlarge_ev_slots(srv);
        found = find_server_slot(srv);
    }
    if (!found)
        return (0);
    found->status = 1;
    found->limit = limit;
    found->exec = ptr;
    clock_gettime(CLOCK_REALTIME, &found->date);
    add_spec(&found->date, to_add);
    return (found);
}
