/*
** EPITECH PROJECT, 2020
** NWP-myftp
** File description:
** my_ftp
*/

#ifndef FTP_COMMAND_H_
#define FTP_COMMAND_H_

#include "ftp.h"

typedef struct ftp_command_s
{
    char *command;
    void (*fct)(server_t *server, client_t *client, char **argv);
} ftp_command;

// Comand

void ftp_quit(server_t *server, client_t *client, char **argv);
void ftp_log(server_t *server, client_t *client, char **argv);
void ftp_pass(server_t *server, client_t *client, char **argv);
void ftp_noop(server_t *server, client_t *client, char **argv);
void ftp_help(server_t *server, client_t *client, char **argv);
void ftp_pasv(server_t *server, client_t *client, char **argv);
void ftp_cwd(server_t *server, client_t *client, char **argv);
void ftp_cdup(server_t *server, client_t *client, char **argv);
void ftp_del(server_t *server, client_t *client, char **argv);
void ftp_list(server_t *server, client_t *client, char **argv);
void ftp_store(server_t *server, client_t *client, char **argv);
void ftp_retr(server_t *server, client_t *client, char **argv);
void ftp_pwd(server_t *server, client_t *client, char **argv);

static const ftp_command tab_cmd[] = {
    {"QUIT", &ftp_quit},
    {"USER", &ftp_log},
    {"PASS", &ftp_pass},
    {"NOOP", &ftp_noop},
    {"HELP", &ftp_help},
    {"CWD", &ftp_cwd},
    {"CDUP", &ftp_cdup},
    {"PASV", &ftp_pasv},
    {"LIST", &ftp_list},
    {"PWD", &ftp_pwd},
    {"RETR", &ftp_retr},
    {"DELE", &ftp_del},
    {"STOR", &ftp_store},
    {"NULL", NULL}
};

#endif