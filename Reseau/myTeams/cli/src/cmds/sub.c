/*
** EPITECH PROJECT, 2021
** teams
** File description:
** sub cmds
*/

#include <stdio.h>

void subscribe(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP SUB %s\n", buf[1]);
}

void unsubscribe(int len, char **buf, int socket)
{
    if (len == 2)
        dprintf(socket, "TCP UNSUB %s\n", buf[1]);
}

void subscribed(int len, char **buf, int socket)
{
    if (len == 1)
        dprintf(socket, "TCP SUB?\n");
    else
        dprintf(socket, "TCP SUB? %s\n", buf[1]);
}
