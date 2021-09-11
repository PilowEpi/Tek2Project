/*
** EPITECH PROJECT, 2021
** teams
** File description:
** create cmds
*/

#include <stdio.h>

void use(int len, char **buf, int socket)
{
    if (len > 1)
        dprintf(socket, "TCP USET %s\n", buf[1]);
    else
        dprintf(socket, "TCP USET\n");
    if (len > 2)
        dprintf(socket, "TCP USEC %s\n", buf[2]);
    else
        dprintf(socket, "TCP USEC\n");
    if (len == 4)
        dprintf(socket, "TCP USETR %s\n", buf[3]);
    else
        dprintf(socket, "TCP USETR\n");
}

void create(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP CREATE \"%s\"\n", buf[1]);
    else if (len == 3)
        dprintf(socket, "TCP CREATE \"%s\" \"%s\"\n", buf[1], buf[2]);
}

void list(int len, char **buf, int socket)
{
    if (len == 1)
        dprintf(socket, "TCP LIST\n");
}

void info(int len, char **buf, int socket)
{
    if (len == 1)
        dprintf(socket, "TCP INFO\n");
}
