/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cmd parsing
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"

void check_cmd_part(char *ptr)
{
    if (!ptr)
        return;
    for (int i = 0; ptr[i] != 0; i++) {
        if (ptr[i] == '\r' || ptr[i] == '\n')
            ptr[i] = 0;
    }
}

char **split(char *buf)
{
    char **res = malloc(sizeof(char *) * 2);
    char delim[] = " ";
    char *ptr = strtok(buf, delim);
    size_t i = 2;

    res[0] = ptr;
    res[1] = 0;
    while (ptr != NULL) {
        ptr = strtok(NULL, delim);
        check_cmd_part(ptr);
        res = reallocarray(res, i + 1, sizeof(char *));
        res[i - 1] = ptr;
        res[i] = 0;
        i++;
    }
    return (res);
}

char **split_expect(char *buf, int fd, int expect)
{
    char **res = split(buf);
    size_t i = 0;

    for (; res[i] != 0; i++);
    if (i == expect)
        return res;
    free(res);
    dprintf(fd, ROGM);
    return 0;
}

void exec_msg(int fd, char *buf, server_t *srv)
{
    conn_t *usr = get_user_fd(srv, fd);
    char *cmds[] = {"LOGIN", "LOGOUT", "SUB?", "SUB", "UNSUB", "USETR", "USEC",
        "USET", "CREATE", "LIST", "INFO", "HMES", "USERS", "USER", "MES", 0};
    void (*fnts[])(char *, conn_t *, server_t *) = {login, logout, subq, sub,
        unsub, usetr, usec, uset, create, list,
        info, hmes, users, user, mes, 0};
    int i = 0;

    for (; cmds[i] != 0; i++)
        if (!strncmp(cmds[i], buf, strlen(cmds[i])))
            break;
    if (i < 2 || (usr->user && cmds[i]))
        fnts[i](buf, usr, srv);
    else if (!cmds[i] || !usr)
        dprintf(fd, usr ? MATR : MATD);
    else
        dprintf(fd, "TCP EV18\n");
}

void parse_msg(int fd, char *buf, server_t *srv)
{
    char **mains = parts_main(buf);

    for (int i = 0; mains[i]; i++) {
        if (!strlen(mains[i]))
            continue;
        if (strncmp(buf, "TCP ", 4))
            dprintf(fd, MATR);
        else
            exec_msg(fd, mains[i] + 4, srv);
    }
    free(mains);
}
