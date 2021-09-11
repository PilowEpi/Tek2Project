/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

int push_client(server_t *server, client_t *client)
{
    client_t *copy = server->list;

    if (!server || !client)
        handle_error("PUSH_CLIENT");
    if (!copy) {
        client->next = NULL;
        server->list = client;
        return (1);
    }
    copy->prev = client;
    client->next = copy;
    server->list = client;
    server->nb_client++;
    return (2);
}

void delete_client(server_t *server, client_t *client)
{
    if (server->list == client)
        server->list = client->next;
    if (client->next)
        client->next->prev = client->prev;
    if (client->prev)
        client->prev->next = client->next;
    FD_CLR(client->socket, &server->available_s);
    shutdown(client->socket, SHUT_RDWR);
    if (client->data_socket != -3)
        shutdown(client->data_socket, SHUT_RDWR);
    if (client->name != NULL) free(client->name);
    free(client);
}

int pop_client(server_t *server, int socket)
{
    client_t *head = server->list;

    while (!head) {
        if (head->socket == socket)
            break;
        head = head->next;
    }
    delete_client(server, head);
    return (0);
}

client_t *get_client(server_t *server, int socket)
{
    for (client_t *tmp = server->list; tmp != NULL; tmp = tmp->next) {
        if (tmp->socket == socket)
            return tmp;
    }
    return (NULL);
}

void print_list(server_t *server)
{
    for (client_t *tmp = server->list; tmp != NULL; tmp = tmp->next) {
        printf("CLIENT : %p\n", tmp);
        printf("\tsocket: %d\n", tmp->socket);
        printf("\tname : %s\n", tmp->name);
        printf("\tis_log: %d\n", tmp->is_log);
        printf("\tnext: %p\n", tmp->next);
        printf("\tprev: %p\n", tmp->prev);
    }
}