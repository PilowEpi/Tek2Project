/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main
*/

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

#include "zappy.h"

int create_socket(int port)
{
    struct sockaddr_in addr;
    int sfd;

    sfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sfd == -1)
        errx(84, "socket create error");
    if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int)) < 0)
        errx(84, "setsockopt(SO_REUSEADDR) failed");
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sfd, (struct sockaddr *) &addr,
        sizeof(struct sockaddr_in)) == -1)
        errx(84, "BIND error");
    if (listen(sfd, 3) != 0)
        errx(84, "LISTEN error");
    return (sfd);
}

int main(int ac, char **av)
{
    server_t *server = init_server();
    int socket = create_socket(server->port);
    int ret = 0;

    srand(time(0));
    ret = handle_args(ac, av, server);
    if (ret) {
        free(server);
        return (ret - 1);
    }
    printf("Port: %d\n", server->port);
    loop(socket, server);
    return (0);
}
