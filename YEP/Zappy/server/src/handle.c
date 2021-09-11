/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** events handling
*/

#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#include "zappy.h"

void exec_event(event_t *ev)
{
    ev->status = 0;
    ev->exec(ev);
    memset(ev, 0, sizeof(event_t));
}

event_t *poll_event(player_t *player, struct timespec *now)
{
    for (int i = 0; i < 10; i++) {
        if (player->evs[i].status &&
            is_event_closer(&player->evs[i].date, now))
            return (&player->evs[i]);
    }
    for (int i = 0; player->srv->s_evs[i]; i++) {
        if (player->srv->s_evs[i]->status &&
            is_event_closer(&player->srv->s_evs[i]->date, now))
            return (player->srv->s_evs[i]);
    }
    return (0);
}

void die(player_t *pl)
{
    write(pl->buf->fd, "dead\n", 5);
    shutdown(pl->buf->fd, SHUT_RDWR);
    close(pl->buf->fd);
    broad_die(pl);
    remove_client(pl->buf->fd, pl->srv);
}

void handle_events(server_t *srv)
{
    event_t *event;
    struct timespec now;

    clock_gettime(CLOCK_REALTIME, &now);
    for (int i = 0; srv->players[i]; i++) {
        while (event = poll_event(srv->players[i], &now))
            exec_event(event);
        if (srv->players[i]->status == PLAYER &&
            is_event_closer(&srv->players[i]->death, &now))
            die(srv->players[i]);
    }
}
