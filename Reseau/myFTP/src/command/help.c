/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"
#include "ftp_command.h"

void ftp_help(server_t *serve __attribute__((unused)),
            client_t *client,
            char **argv __attribute__((unused)))
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    dprintf(client->socket, "214-The following commands are recognized.\r\n");
    for (int i = 0; tab_cmd[i].fct != NULL; i++) {
        dprintf(client->socket, " %s", tab_cmd[i].command);
        if (i + 1 % 5 == 0)
            dprintf(client->socket, "\r\n");
    }
    dprintf(client->socket, "\r\n");
    dprintf(client->socket, "214 Help OK.\r\n");
}