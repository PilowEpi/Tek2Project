/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create
*/

#include <stdlib.h>
#include <err.h>

#include "server.h"

void create_team(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split_expect_quoted(buf, usr->fd, 3);
    team_t *team = malloc(sizeof(team_t));

    if (!team)
        errx(84, "malloc failed");
    if (!cmd || exist_team(cmd[1], srv))
        free(team);
    if (!cmd || !ck_m(usr, cmd[1], srv) ||
        init_team(team, cmd[1], cmd[2], usr))
        return;
    append_team(srv, team);
    broad_team(team, usr, srv);
    free(cmd);
}

void create_channel(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split_expect_quoted(buf, usr->fd, 3);
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = malloc(sizeof(chan_t));
    int i = 0;

    if (!chan)
        errx(84, "malloc failed");
    if (!cmd || !check_auth(usr, usr->user->team) ||
        exist_cn(cmd[1], srv, usr->user))
        free(chan);
    if (!cmd || !ck_c(usr, cmd[1], srv) ||
        init_channel(chan, cmd[1], cmd[2], usr))
        return;
    append_channel(team, chan);
    broad_chan(chan, usr, srv);
    free(cmd);
}

void create_thread(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split_expect_quoted(buf, usr->fd, 3);
    team_t *team = find_team_id(usr->user->team, srv);
    chan_t *chan = find_chan_id(usr->user->channel, team);
    thread_t *thread = malloc(sizeof(thread_t));

    if (!thread)
        errx(84, "malloc failed");
    if (!cmd || !check_auth(usr, usr->user->team) ||
        exist_thr(cmd[1], srv, usr->user))
        free(thread);
    if (!cmd || !ck_t(usr, cmd[1], srv) ||
        init_thread(thread, cmd[1], cmd[2], usr))
        return;
    append_thread(chan, thread);
    broad_thread(thread, usr, srv);
    free(cmd);
}

void create_reply(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split_expect_quoted(buf, usr->fd, 2);
    thread_t *thread = get_current_thread(usr->user, srv);
    msg_t *message = malloc(sizeof(msg_t));

    if (!message)
        errx(84, "malloc failed");
    if (!cmd || !check_auth(usr, usr->user->team))
        free(message);
    if (!cmd || !ck_a(usr) || init_message(message, cmd[1], usr))
        return;
    append_reply(thread, message);
    broad_reply(message, usr, srv);
    free(cmd);
}

void create(char *buf, conn_t *usr, server_t *srv)
{
    if (uuid_is_null(usr->user->team)) {
        create_team(buf, usr, srv);
        save_teams(srv->teams);
        return;
    } else if (uuid_is_null(usr->user->channel)){
        if (!g_team(usr, srv))
            return;
        create_channel(buf, usr, srv);
        save_teams(srv->teams);
        return;
    }
    if (uuid_is_null(usr->user->thread)) {
        if (!g_chan(usr, srv))
            return;
        create_thread(buf, usr, srv);
    } else if (g_thread(usr, srv)) {
        create_reply(buf, usr, srv);
    }
    save_teams(srv->teams);
}
