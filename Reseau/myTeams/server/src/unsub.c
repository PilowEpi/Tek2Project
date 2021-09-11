/*
** EPITECH PROJECT, 2021
** teams
** File description:
** unsub
*/

#include <stdlib.h>
#include <stdio.h>

#include "server.h"
#include "logging_server.h"

void do_unsub(conn_t *usr, uuid_t team)
{
    int passed = 0;
    char t_id[UUID_LENGTH];
    char user[UUID_LENGTH];

    uuid_unparse_upper(usr->user->id, user);
    uuid_unparse_upper(team, t_id);
    for (int i = 0; !uuid_is_null(usr->user->subbed[i]); i++) {
        if (!uuid_compare(usr->user->subbed[i], team))
            passed = 1;
        if (!passed)
            continue;
        uuid_copy(usr->user->subbed[i], usr->user->subbed[i + 1]);
    }
    server_event_user_unsubscribed(t_id, user);
    dprintf(usr->fd, "TCP EV29 \"%s\" \"%s\"\n", user, t_id);
}

void unsub(char *buf, conn_t *usr, server_t *srv)
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
    do_unsub(usr, team);
    save_regs(srv->regs);
    free(cmd);
}
