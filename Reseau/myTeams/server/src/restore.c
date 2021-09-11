/*
** EPITECH PROJECT, 2021
** teams
** File description:
** restore
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "server.h"
#include "logging_server.h"

void restore_user(int fd, user_t *usr)
{
    int n_sub;
    int n_msg;

    read(fd, usr, sizeof(user_t));
    read(fd, &n_sub, sizeof(n_sub));
    usr->subbed = calloc(n_sub + 1, sizeof(uuid_t));
    for (int j = 0; j < n_sub; j++)
        read(fd, usr->subbed[j], sizeof(uuid_t));
    read(fd, &n_msg, sizeof(n_msg));
    usr->private = calloc(n_msg + 1, sizeof(msg_t *));
    for (int j = 0; j < n_msg; j++) {
        usr->private[j] = malloc(sizeof(msg_t));
        read(fd, usr->private[j], sizeof(msg_t));
    }
}

void restore_regs(server_t *srv)
{
    struct stat st = {0};
    int fd = 0;
    int n_regs = 0;
    char id[UUID_LENGTH];

    if (stat("data", &st) == -1 ||
        stat("data/users.dat", &st) == -1)
        return;
    fd = open("data/users.dat", O_RDONLY);
    read(fd, &n_regs, sizeof(n_regs));
    srv->regs = reallocarray(srv->regs, n_regs + 1, sizeof(user_t *));
    srv->regs[n_regs] = 0;
    for (int i = 0; i < n_regs; i++) {
        srv->regs[i] = malloc(sizeof(user_t));
        restore_user(fd, srv->regs[i]);
        uuid_unparse_upper(srv->regs[i]->id, id);
        server_event_user_loaded(id, srv->regs[i]->username);
    }
}

void restore_thread(int fd, thread_t *thr)
{
    int n_msg = 0;

    read(fd, thr, sizeof(thread_t));
    read(fd, &n_msg, sizeof(n_msg));
    thr->messages = calloc(n_msg + 1, sizeof(msg_t *));
    for (int j = 0; j < n_msg; j++) {
        thr->messages[j] = malloc(sizeof(msg_t));
        read(fd, thr->messages[j], sizeof(msg_t));
    }
}

void restore_team(int fd, team_t *team)
{
    int n_chan;
    int n_thr;

    read(fd, team, sizeof(team_t));
    read(fd, &n_chan, sizeof(n_chan));
    team->channels = calloc(n_chan + 1, sizeof(chan_t *));
    for (int j = 0; j < n_chan; j++) {
        team->channels[j] = malloc(sizeof(chan_t));
        read(fd, team->channels[j], sizeof(chan_t));
        read(fd, &n_thr, sizeof(n_thr));
        team->channels[j]->threads = calloc(n_thr + 1, sizeof(thread_t *));
        for (int i = 0; i < n_thr; i++) {
            team->channels[j]->threads[i] = malloc(sizeof(thread_t)),
            restore_thread(fd, team->channels[j]->threads[i]);
        }
    }
}

void restore_teams(server_t *srv)
{
    struct stat st = {0};
    int fd = 0;
    int n_team = 0;

    if (stat("data", &st) == -1 ||
        stat("data/teams.dat", &st) == -1)
        return;
    fd = open("data/teams.dat", O_RDONLY);
    read(fd, &n_team, sizeof(n_team));
    srv->teams = reallocarray(srv->teams, n_team + 1, sizeof(team_t *));
    srv->teams[n_team] = 0;
    for (int i = 0; i < n_team; i++) {
        srv->teams[i] = malloc(sizeof(team_t));
        restore_team(fd, srv->teams[i]);
    }
}
