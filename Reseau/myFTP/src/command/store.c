/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int check_error_store(client_t *client, char **argv)
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return (-1);
    }
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

void read_all(int file, int fd)
{
    char buff[1024];
    int len = 0;

    while ((len = read(fd, buff, 1024))) {
        dprintf(file, "%s", buff);
    }
}

void store_pasv(int fd)
{
    int pid = 0;
    int size = sizeof(struct SA_IN);
    int client_socket;
    struct SA_IN addr;

    client_socket = accept(fd, (struct SA *)&addr,
        (socklen_t *)&size);
    dup2(client_socket, 1);
    pid = fork();
    if (pid == 0) {
        read_all(fd, client_socket);
        exit(0);
    }
    close(client_socket);
    close(fd);
    waitpid(pid, 0, 0);
}

void store_acti(int fd __attribute__((unused)))
{

}

void ftp_store(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv)
{
    int fd;

    if (check_error_store(client, argv) == -1)
        return;
    fd = open(argv[1], O_CREAT | O_WRONLY, 0644);
    if (fd < 0) {
        dprintf(client->socket, "553 Failed to create the file\r\n");
        return;
    }
    dprintf(client->socket, "150 Transfert starting\r\n");
    if (client->mode == 1)
        store_pasv(fd);
    else if (client->mode == 2)
        store_acti(fd);
    dprintf(client->socket, "226 Transfert complete.\r\n");

    client->mode = 0;
}