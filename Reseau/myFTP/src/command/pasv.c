/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int create_data_socket(void)
{
    int data_socket;
    struct SA_IN addr;

    data_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (data_socket == -1) handle_error("SOCKET");
    addr.sin_port = htons(0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(data_socket, (struct SA *)&addr,
        sizeof(struct SA_IN)) == -1)
        handle_error("BIND");
    if (listen(data_socket, FTP_MAX_TIMEOUT) == -1)
        handle_error("LISTEN");
    return (data_socket);
}

void print_port(int client_socket, int socket)
{
    struct sockaddr_in IN;
    socklen_t len = sizeof(IN);
    int base_port;
    int port1;
    int port2;

    if (getsockname(socket, (struct sockaddr *)&IN, &len) == -1)
        handle_error("GETSOCKNAME");
    base_port = ntohs(IN.sin_port);
    printf("port number %d\n", base_port);
    port1 = base_port / 256;
    port2 = base_port % 256;
    dprintf(client_socket, "%d,%d).\r\n", port1, port2);
}

void ftp_pasv(server_t *server __attribute__((unused)),
            client_t *client,
            char **argv __attribute__((unused)))
{
    if (client->is_log != 2) {
        dprintf(client->socket, "530 Please login with USER and PASS.\r\n");
        return;
    }
    client->data_socket = create_data_socket();
    dprintf(client->socket, "227 Entering Passive Mode (0,0,0,0,");
    print_port(client->socket, client->data_socket);
    client->mode = 1;
}