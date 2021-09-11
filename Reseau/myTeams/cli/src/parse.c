/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cli preprocess
*/

#include <string.h>
#include <stdlib.h>

#include "cli.h"

void parse_part(char *buffer, int socket)
{
    char **cmd = split_quoted(buffer, 0);
    int len = 0;
    int i = 0;
    char *cmds[] = {"/help", "/login", "/logout", "/users", "/user", "/send",
        "/messages", "/subscribed", "/subscribe", "/unsubscribe", "/use",
        "/create", "/list", "/info", 0};
    void (*fnts[])(int, char **, int) = {help, login, logout, users, user,
        sendc, messages, subscribed, subscribe, unsubscribe, use, create,
        list, info, 0};

    for (; cmd && cmd[len]; len++);
    for (; cmd && cmds[i] != 0; i++)
        if (!strncmp(cmds[i], cmd[0], strlen(cmds[i])))
            break;
    if (cmds[i])
        fnts[i](len, cmd, socket);
}

void parse(char *buffer, int socket)
{
    char **mains = parts_main(buffer);

    for (int i = 0; mains[i]; i++) {
        if (!strlen(mains[i]))
            continue;
        parse_part(mains[i], socket);
    }
    free(mains);
}
