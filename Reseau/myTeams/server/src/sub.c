/*
** EPITECH PROJECT, 2021
** teams
** File description:
** sub
*/

#include <stdlib.h>
#include <stdio.h>
#include <err.h>

#include "server.h"
#include "logging_server.h"

void send_teams(team_t *team, conn_t *usr)
{
    char uuid_buf[UUID_LENGTH];

    if (!team) {
        dprintf(usr->fd, MATD);
        return;
    }
    uuid_unparse_upper(team->id, uuid_buf);
    dprintf(usr->fd, "TCP EV9 \"%s\" \"%s\" \"%s\"\n",
        uuid_buf, team->name, team->desc);
}

void send_subscribed(uuid_t id, conn_t *usr, server_t *srv)
{
    char uuid_buf[UUID_LENGTH];

    if (!find_team_id(id, srv)) {
        uuid_unparse_upper(id, uuid_buf);
        dprintf(usr->fd, "TCP EV14 \"%s\"\n", uuid_buf);
        return;
    }
    for (int i = 0; srv->regs[i]; i++) {
        if (!is_user_in_team(srv->regs[i], id))
            continue;
        uuid_unparse_upper(srv->regs[i]->id, uuid_buf);
        dprintf(usr->fd, "TCP EV8 \"%s\" \"%s\" \"%d\"\n",
            uuid_buf, srv->regs[i]->username,
            is_user_connected(srv->regs[i]->id, srv));
    }
}

void subq(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split(buf);
    int len = 0;
    team_t *team;
    uuid_t team_id;

    for (; cmd[len]; len++);
    if (len == 1) {
        for (int i = 0; !uuid_is_null(usr->user->subbed[i]); i++) {
            team = find_team_id(usr->user->subbed[i], srv);
            send_teams(team, usr);
        }
    } else if (len == 2) {
        if (uuid_parse(cmd[1], team_id))
            dprintf(usr->fd, MATR);
        else
            send_subscribed(team_id, usr, srv);
    }
    free(cmd);
}

void do_sub(conn_t *usr, uuid_t team)
{
    int i = 0;
    char t_id[UUID_LENGTH];
    char user[UUID_LENGTH];

    uuid_unparse_upper(usr->user->id, user);
    uuid_unparse_upper(team, t_id);
    for (; !uuid_is_null(usr->user->subbed[i]); i++);
    usr->user->subbed = reallocarray(usr->user->subbed, i + 2, sizeof(uuid_t));
    if (!usr->user->subbed)
        errx(84, "realloc failed");
    uuid_copy(usr->user->subbed[i], team);
    uuid_clear(usr->user->subbed[i + 1]);
    server_event_user_subscribed(t_id, user);
    dprintf(usr->fd, "TCP EV28 \"%s\" \"%s\"\n", user, t_id);
}

void sub(char *buf, conn_t *usr, server_t *srv)
{
    char **cmd = split_expect(buf, usr->fd, 2);
    uuid_t team;

    if (!cmd)
        return;
    if (uuid_parse(cmd[1], team)) {
        dprintf(usr->fd, MATR);
        return;
    }
    if (!find_team_id(team, srv)) {
        dprintf(usr->fd, "TCP EV14 \"%s\"\n", cmd[1]);
        return;
    }
    do_sub(usr, team);
    save_regs(srv->regs);
    free(cmd);
}
