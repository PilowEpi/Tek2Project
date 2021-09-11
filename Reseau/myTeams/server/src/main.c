/*
** EPITECH PROJECT, 2019
** project
** File description:
** main
*/

#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <signal.h>

#include "server.h"

int chk_digit(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!isdigit(str[i]))
            return (1);
    return (0);
}

server_t *init_struct(void)
{
    server_t *srv = malloc(sizeof(server_t));

    if (!srv)
        errx(84, "malloc error");
    srv->regs = malloc(sizeof(user_t *));
    srv->conns = malloc(sizeof(conn_t *));
    srv->teams = malloc(sizeof(team_t *));
    if (!srv->regs || !srv->conns || !srv->teams)
        errx(84, "malloc error");
    srv->regs[0] = 0;
    srv->conns[0] = 0;
    srv->teams[0] = 0;
    restore_regs(srv);
    restore_teams(srv);
    return (srv);
}

void free_server(server_t *srv)
{
    free(srv->conns);
    free(srv->regs);
    free(srv);
}

void handler(int sig)
{
    exit(0);
}

int main(int ac, char **av)
{
    int socket;
    server_t *srv;

    if (ac == 2 && !strcmp(av[1], "-help")) {
        printf(USAGE);
        return (0);
    }
    if (ac != 2 || chk_digit(av[1]))
        return (84);
    signal(SIGINT, handler);
    srv = init_struct();
    socket = create_socket(atoi(av[1]), srv);
    loop(socket, srv);
    free_server(srv);
    return (0);
}
