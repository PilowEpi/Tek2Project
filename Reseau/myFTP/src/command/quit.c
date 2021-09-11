/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void ftp_quit(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv __attribute__((unused)))
{
    dprintf(client->socket, "221 Goodbye.\r\n");
    client->to_delete = 1;
}