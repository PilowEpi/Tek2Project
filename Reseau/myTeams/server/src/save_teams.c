/*
** EPITECH PROJECT, 2021
** teams
** File description:
** save
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "server.h"

void write_channel(int fd, chan_t *chan)
{
    int n_thr = 0;

    for (; chan->threads[n_thr]; n_thr++);
    write(fd, chan, sizeof(chan_t));
    write(fd, &n_thr, sizeof(n_thr));
    for (int i = 0; i < n_thr; i++) {
        write(fd, chan->threads[i], sizeof(thread_t));
        write_messages(fd, chan->threads[i]->messages);
    }
}

void write_team(int fd, team_t *team)
{
    int n_chan = 0;

    for (; team->channels[n_chan]; n_chan++);
    write(fd, team, sizeof(team_t));
    write(fd, &n_chan, sizeof(n_chan));
    for (int i = 0; i < n_chan; i++)
        write_channel(fd, team->channels[i]);
}

void save_teams(team_t **teams)
{
    int fd = 0;
    int i = 0;
    struct stat st = {0};

    for (; teams[i]; i++);
    if (stat("data", &st) == -1)
        mkdir("data", 0700);
    fd = open("data/teams.dat", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    write(fd, &i, sizeof(i));
    for (int j = 0; j < i; j++)
        write_team(fd, teams[j]);
}
