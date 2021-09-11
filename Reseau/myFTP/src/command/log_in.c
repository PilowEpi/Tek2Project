/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void ftp_log(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv)
{
    if (argv[1] != NULL)
        client->name = strdup(argv[1]);
    client->is_log = 1;
    dprintf(client->socket, "331 Please specify the password.\r\n");
}

void ftp_pass(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv __attribute__((unused)))
{
    if (client->name == NULL ||
        strcmp(client->name, "Anonymous")) {
        dprintf(client->socket, "530 Login incorrect.\r\n");
        client->is_log = 0;
        if (client->name != NULL)
            free(client->name);
        return;
    }
    client->is_log = 2;
    dprintf(client->socket, "230 Login successful.\r\n");
}
