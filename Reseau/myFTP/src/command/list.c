/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

void put_ls_in_fd(int fd, char *dir)
{
    int stout = dup(1);
    char *argv[] = {"/bin/ls", "-l", dir, NULL};
    int pid = 0;
    int size = sizeof(struct SA_IN);
    int client_socket;
    struct SA_IN addr;

    client_socket = accept(fd, (struct SA *)&addr,
        (socklen_t *)&size);
    dup2(client_socket, 1);
    pid = fork();
    if (pid == 0) {
        execv("/bin/ls", argv);
        exit(0);
    }
    close(client_socket);
    close(fd);
    dup2(stout, 1);
    waitpid(pid, 0, 0);
}

void ftp_list(server_t *server, client_t *client, char **argv)
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    } else if (client->mode == 0) {
        dprintf(client->socket, "425 Use PORT or PASV first.\r\n");
        return;
    }
    if (argv[1] == NULL)
        put_ls_in_fd(client->data_socket, server->path);
    else if (argv[1] != NULL)
        put_ls_in_fd(client->data_socket, argv[1]);
    dprintf(client->socket, "150 Here comes the directory listing.\r\n");
    dprintf(client->socket, "226 Directory send OK.\r\n");
    client->mode = 0;
}