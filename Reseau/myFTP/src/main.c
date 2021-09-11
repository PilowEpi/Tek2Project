/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int print_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport  is the port number on which the server socket listens\n");
    printf("\tpath  is the path to the home directory ");
    printf("for the Anonymous user\n");
    return (0);
}

void handle_error(char *msg_err)
{
    do {
        perror(msg_err);
        exit(84);
    } while (0);
}

int get_port(const char *p)
{
    for (int i = 0; p[i]; i++) {
        if (p[i] <= '0' && p[i] >= '9')
            exit(84);
    }
    return (atoi(p));
}

int init_ftp(char *p, char *path)
{
    server_t *server = malloc(sizeof(server_t));

    if (!server)
        handle_error("MALLOC");
    server->port = get_port(p);
    server->socket = setup_server(server->port, FTP_MAX_TIMEOUT);
    server->list = NULL;
    server->path = realpath(path, NULL);
    chdir(server->path);

    if (server->path == NULL) {
        dprintf(2, "Bad path: %s\n", path);
        return (84);
    }
    return (launch_server(server));
}

int main(int argc, char **argv)
{
    if (argc == 2 && !strcmp(argv[1], "-help"))
        return (print_usage());
    else if (argc == 3)
        return (init_ftp(argv[1], argv[2]));
    return (84);
}