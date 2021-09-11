/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void ftp_del(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv)
{
    int error = 0;

    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    if (argv[1] == NULL || argv[2] != NULL || !realpath(argv[1], NULL)) {
        dprintf(client->socket, "550 Permission denied.\r\n");
        return;
    }
    error = remove(argv[1]);
    if (error != 0) {
        dprintf(client->socket, "550 Permission denied.\r\n");
        return;
    }
    dprintf(client->socket, "250 Directory successfully deleted.\r\n");
}