/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void ftp_cwd(server_t *server, client_t *client, char **argv)
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    if (argv[1] == NULL || argv[2] != NULL || !realpath(argv[1], NULL)) {
        dprintf(client->socket, "550 Failed to change directory.\r\n");
        return;
    }
    dprintf(client->socket, "250 Directory successfully changed.\r\n");
    free(server->path);
    chdir(server->path);
    server->path = strdup(argv[1]);
}

void ftp_cdup(server_t *server,
            client_t *client,
            char **argv __attribute__((unused)))
{
    char cwd[256];
    int dir = 0;

    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    dir = chdir("..");
    if (dir != 0) {
        dprintf(client->socket, "550 Failed to change directory.\r\n");
        return;
    }
    dprintf(client->socket, "200 Directory successfully changed.\r\n");
    free(server->path);
    server->path = strdup(getcwd(cwd, sizeof(cwd)));
}

void ftp_pwd(server_t *server, client_t *client, char **argv)
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    dprintf(client->socket, "257 \"%s\"\r\n", server->path);
}