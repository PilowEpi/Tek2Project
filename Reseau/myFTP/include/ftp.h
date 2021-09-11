/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#ifndef FTP_H_
#define FTP_H_

// Include

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <netinet/in.h>
#include <netinet/ip.h>

// Macro

#define SA_IN sockaddr_in
#define SA_UN sockaddr_un
#define SA_OUT sockaddr_out
#define SA sockaddr

#define READ_SIZE 1024

#define FTP_MAX_TIMEOUT 100

// Structure

typedef struct client_s {
    int is_log;
    int socket;
    int to_delete;
    char *name;
    int mode;
    int data_socket;
    struct client_s *next;
    struct client_s *prev;
} client_t;

typedef struct server_s {
    int socket;
    int port;
    char *path;
    int nb_client;
    fd_set available_s;
    fd_set ready_s;
    client_t *list;
} server_t;

//
// Error
//

void handle_error(char *msg_err);

//
// Server
//

// base

int init_ftp(char *p, char *path);
int launch_server(server_t *server);
int close_server(server_t *server);
int setup_server(int port, int timeout);

// command

int do_command(server_t *server, client_t *client, char **argv);
int index_of_command(char *command);

//
//  Client
//

// base

client_t *create_client(int socket);
int accept_client(int server_socket);
char **client_response(int client_socket);
char *read_response_from_socket(int client_socket);

// utils

int push_client(server_t *server, client_t *client);
int pop_client(server_t *server, int socket);
void print_list(server_t *server);
client_t *get_client(server_t *server, int socket);

// handle

int handle_connection(server_t *server, client_t *client);
int handle_client(server_t *server, int client_s);
int catch_client(server_t *server);


// String

char **my_str_to_word_array(char const *str);
void free_array(char **array);

#endif