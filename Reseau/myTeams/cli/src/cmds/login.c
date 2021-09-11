/*
** EPITECH PROJECT, 2021
** teams
** File description:
** login cmds
*/

#include <stdio.h>

void help(int len, char **buf, int socket)
{
    if (len != 1)
        return;
    printf("help!\n");
}

void login(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP LOGIN %s\n", buf[1]);
}

void logout(int len, char **buf, int socket)
{
    if (len == 1)
        dprintf(socket, "TCP LOGOUT\n");
}
