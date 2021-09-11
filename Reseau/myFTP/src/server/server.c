/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int setup_server(int port, int timeout)
{
    int server_socket;
    struct SA_IN addr;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) handle_error("SOCKET");
    addr.sin_port = htons(port);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(server_socket, (struct SA *)&addr,
        sizeof(struct SA_IN)) == -1)
        handle_error("BIND");
    if (listen(server_socket, timeout) == -1)
        handle_error("LISTEN");
    return (server_socket);
}

int close_server(server_t *server)
{
    close(server->socket);
    return (0);
}

int launch_server(server_t *server)
{
    FD_ZERO(&server->available_s);
    FD_SET(server->socket, &server->available_s);
    printf("Wait connection\n");
    while (1) {
        server->ready_s = server->available_s;

        if (select(FD_SETSIZE, &server->ready_s, NULL, NULL, NULL) < 0)
            handle_error("SELECT");

        catch_client(server);
    }
    printf("End connection\n");
    print_list(server);
    close_server(server);
    return (0);
}