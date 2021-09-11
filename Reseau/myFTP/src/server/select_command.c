/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"
#include "ftp_command.h"

int index_of_command(char *command)
{
    int i = 0;

    for (i = 0; tab_cmd[i].fct != NULL; i++) {
        if (strcmp(command, tab_cmd[i].command) == 0)
            return (i);
    }
    return (-1);
}

int do_command(server_t *server, client_t *client, char **argv)
{
    int idx = index_of_command(argv[0]);

    if (idx == -1) {
        if (client->is_log != 2)
            dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        else
            dprintf(client->socket, "500 Unknown command.\r\n");
        return (-1);
    }
    tab_cmd[idx].fct(server, client, argv);
    return (0);
}