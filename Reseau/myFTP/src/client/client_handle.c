/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"
#include "ftp_command.h"

int handle_connection(server_t *server, client_t *client)
{
    char **resp = client_response(client->socket);

    if (resp == NULL)
        return (2);
    for (int i = 0; resp[i]; i++) {
        printf("line : %d : response : %s\n", i, resp[i]);
    }
    do_command(server, client, resp);
    free_array(resp);
    return (0);
}

int handle_client(server_t *server, int client_s)
{
    client_t *client = get_client(server, client_s);

    if (client == NULL) {
        printf("Invalid client_t : %d\n", client_s);
        return (0);
    }
    printf("client : %d\n", client->socket);

    handle_connection(server, client);
    return (0);
}

int delete_old_client(server_t *server)
{
    int deleted = 0;

    for (client_t *tmp = server->list; tmp != NULL; tmp = tmp->next) {
        if (tmp->to_delete == 1) {
            printf("Delete : %d\n", tmp->socket);
            pop_client(server, tmp->socket);
            tmp = server->list;
            deleted++;
        }
        if (tmp == NULL)
            break;
    }
    return (deleted);
}

int catch_client(server_t *server)
{
    client_t * new_c;

    for (int i = 0; i < FD_SETSIZE; i++) {
        if (FD_ISSET(i, &server->ready_s)) {
            if (i == server->socket) {
                new_c = create_client(accept_client(server->socket));
                push_client(server, new_c);
                FD_SET(new_c->socket, &server->available_s);
                dprintf(new_c->socket, "220 \r\n");
                printf("Create new client : %d\n", new_c->socket);
            } else {
                handle_client(server, i);
            }
        }
    }
    delete_old_client(server);
    printf("\n\nCurrent client connected : \n");
    print_list(server);
    printf("\n\n");
    return (0);
}