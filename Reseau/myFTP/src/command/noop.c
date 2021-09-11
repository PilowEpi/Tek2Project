/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void ftp_noop(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv __attribute__((unused)))
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    dprintf(client->socket, "200 NOOP ok.\r\n");
}