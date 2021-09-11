/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#include "ftp.h"

char *read_response_from_socket(int client_socket)
{
    char buff[READ_SIZE] = {0};
    char *result = NULL;
    int len = 0;

    len = read(client_socket, buff, READ_SIZE);
    if (len == -1 || len == 0)
        return (NULL);
    if (buff[0] == -1)
        return (NULL);
    result = malloc(len);
    result[len - 1] = '\0';
    memset(result, 0, len - 1);
    memcpy(result, buff, len - 2);
    return (result);
}

int accept_client(int server_socket)
{
    int size = sizeof(struct SA_IN);
    int client_socket;
    struct SA_IN addr;

    client_socket = accept(server_socket, (struct SA *)&addr,
        (socklen_t *)&size);
    if (client_socket == -1)
        handle_error("ACCEPT");
    return (client_socket);
}

char **client_response(int client_socket)
{
    char *client_response = read_response_from_socket(client_socket);
    char **response = NULL;

    if (client_response == NULL)
        return (NULL);

    response = my_str_to_word_array(client_response);
    free(client_response);
    return (response);
}

client_t *create_client(int socket)
{
    client_t *new_client = malloc(sizeof(client_t));

    if (new_client == NULL)
        handle_error("CREATE_CLIENT");
    new_client->socket = socket;
    new_client->data_socket = -3;
    new_client->mode = 0;
    new_client->is_log = 0;
    new_client->to_delete = 0;
    new_client->name = NULL;
    new_client->prev = NULL;
    return (new_client);
}