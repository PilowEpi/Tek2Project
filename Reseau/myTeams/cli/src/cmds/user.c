/*
** EPITECH PROJECT, 2021
** teams
** File description:
** user cmds
*/

#include <stdio.h>

void users(int len, char **buf, int socket)
{
    if (len == 1)
        dprintf(socket, "TCP USERS\n");
}

void user(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP USER %s\n", buf[1]);
}

void sendc(int len, char **buf, int socket)
{
    if (len == 3)
        dprintf(socket, "TCP MES \"%s\" \"%s\"\n", buf[1], buf[2]);
}

void messages(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP HMES %s\n", buf[1]);
}
