/*
** EPITECH PROJECT, 2019
** project
** File description:
** main
*/

#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <err.h>

#include "cli.h"

int chk_digit(char *str)
{
    for (int i = 0; str[i] != 0; i++)
        if (!isdigit(str[i]))
            return (1);
    return (0);
}

int create_socket(char *ip, int port)
{
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in serv_addr;

    if (sock < 0)
        return (-1);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) < 0) {
        perror("inet_pton");
        return (-1);
    }
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        return (-1);
    }
    return (sock);
}

int main(int ac, char **av)
{
    int socket;

    if (ac == 2 && !strcmp(av[1], "-help")) {
        printf(USAGE);
        return (0);
    }
    if (ac != 3 || chk_digit(av[2]))
        return (84);
    socket = create_socket(av[1], atoi(av[2]));
    if (socket < 0)
        return (84);
    loop(socket);
    return (0);
}
