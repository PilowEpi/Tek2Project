/*
** EPITECH PROJECT, 2021
** teams
** File description:
** cli header
*/

#ifndef _TEAMS_CLI
#define _TEAMS_CLI

#define USAGE "USAGE: ./myteams_cli ip port\n"                          \
    "\tip    is the server ip address on which the server socket listens.\n" \
    "\tport  is the port number on which the server socket listens.\n"

#define DECL_LOG(x)                                  \
    int x(int, char **);

#define DECL_CMD(x)                                  \
    void x(int, char **, int);

// LOGGER CALLBACK

DECL_LOG(ev_lin);
DECL_LOG(ev_lout)
DECL_LOG(ev_private);
DECL_LOG(ev_thr_rep);

DECL_LOG(ev_team);
DECL_LOG(ev_channel);
DECL_LOG(ev_thread);

DECL_LOG(pr_user_list);
DECL_LOG(pr_team_list);
DECL_LOG(pr_channel_list);
DECL_LOG(pr_thread_list);
DECL_LOG(pr_reply_list);
DECL_LOG(pr_private);

DECL_LOG(err_team);
DECL_LOG(err_channel);
DECL_LOG(err_thread);
DECL_LOG(err_user);
DECL_LOG(err_unauth);
DECL_LOG(err_exists);

DECL_LOG(pr_user);
DECL_LOG(pr_team);
DECL_LOG(pr_channel);
DECL_LOG(pr_thread);

DECL_LOG(cr_team);
DECL_LOG(cr_channel);
DECL_LOG(cr_thread);
DECL_LOG(cr_reply);

DECL_LOG(pr_sub);
DECL_LOG(pr_unsub);

// COMMANDS

DECL_CMD(help);
DECL_CMD(login);
DECL_CMD(logout);

DECL_CMD(users);
DECL_CMD(user);
DECL_CMD(sendc);
DECL_CMD(messages);

DECL_CMD(subscribe);
DECL_CMD(unsubscribe);
DECL_CMD(subscribed);

DECL_CMD(use);
DECL_CMD(create);
DECL_CMD(list);
DECL_CMD(info);


#include <time.h>


const static int (*fnts[])(int, char **) = {ev_lin, ev_lout, ev_private,
    ev_thr_rep, ev_team, ev_channel, ev_thread, pr_user_list, pr_team_list,
    pr_channel_list, pr_thread_list, pr_reply_list, pr_private, err_team,
    err_channel, err_thread, err_user, err_unauth, err_exists, pr_user,
    pr_team, pr_channel, pr_thread, cr_team, cr_channel, cr_thread,
    cr_reply, pr_sub, pr_unsub};


void loop(int socket);
void forward_logger(char *buffer);

char **split_quoted(char *msg, int expect);
char **parts_main(char *buf);

void parse(char *buffer, int socket);

char *strptime(const char *s, const char *format, struct tm *tm);

#endif
