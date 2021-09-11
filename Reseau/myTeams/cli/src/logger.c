/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cli logger call
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "cli.h"
#include "logging_client.h"

void log_other(char *buf)
{
}

void log_msg(char *buf)
{
    char **recv = split_quoted(buf, 0);
    int type = 0;
    int len = 0;

    if (!recv)
        return;
    for (; recv[len]; len++);
    type = atoi(recv[0]);
    if (type <= 0 || type > 29){
        printf("no type match: %d\n", type);
        return;
    }
    if (fnts[type - 1](len, recv))
        printf("recv failed: %s\n", recv[0]);
    free(recv);
}

void forward_logger(char *buffer)
{
    char **mains = parts_main(buffer);

    for (int i = 0; mains[i]; i++) {
        if (!strlen(mains[i]))
            continue;
        if (strncmp(mains[i], "TCP EV", 6))
            log_other(mains[i]);
        else
            log_msg(mains[i] + 6);
    }
    free(mains);
}
