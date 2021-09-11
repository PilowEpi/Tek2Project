/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int check_error_retr(client_t *client, char **argv)
{
    if (client->mode == 0) {
        dprintf(client->socket, "425 Use PORT or PASV first.\r\n");
        return (-1);
    }
    if (argv[1] == NULL) {
        dprintf(client->socket, "550 Failed to open file.\r\n");
        return (-1);
    }
    return (0);
}

void retr_acti(client_t *client __attribute__((unused)), char **argv, int fd)
{
    int stout = dup(1);
    char *args[] = {"/bin/cat", argv[1], NULL};
    int pid = 0;
    int size = sizeof(struct SA_IN);
    int client_socket;
    struct SA_IN addr;

    client_socket = accept(fd, (struct SA *)&addr,
        (socklen_t *)&size);
    dup2(client_socket, 1);
    pid = fork();
    if (pid == 0) {
        execv("/bin/cat", args);
        exit(0);
    }
    close(client_socket);
    close(fd);
    dup2(stout, 1);
    waitpid(pid, 0, 0);
}

void retr_pasv(client_t *client __attribute__((unused)), char **argv, int fd)
{
    int stout = dup(1);
    char *args[] = {"/bin/cat", argv[1], NULL};
    int pid = 0;
    int size = sizeof(struct SA_IN);
    int client_socket;
    struct SA_IN addr;

    client_socket = accept(fd, (struct SA *)&addr,
        (socklen_t *)&size);
    dup2(client_socket, 1);
    pid = fork();
    if (pid == 0) {
        execv("/bin/cat", args);
        exit(0);
    }
    close(client_socket);
    close(fd);
    dup2(stout, 1);
    waitpid(pid, 0, 0);
}

void ftp_retr(server_t *server __attribute__((unused)),
        client_t *client, char **argv)
{
    int fd = (client->mode == 1) ? client->data_socket : client->socket;
    int file;

    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    if (check_error_retr(client, argv) == -1)
        return;
    file = open(argv[1], O_RDONLY);
    if (file == -1) {
        dprintf(client->socket, "550 Failed to open file.\r\n");
        return;
    }
    close(file);
    if (client->mode == 1)
        retr_pasv(client, argv, fd);
    else if (client->mode == 2)
        retr_acti(client, argv, fd);
    client->mode = 0;
}