/*
** EPITECH PROJECT, 2021
** teams
** File description:
** include
*/

#ifndef _MY_TEAMS_SRV
#define _MY_TEAMS_SRV


#define MATR  "MATR Syntax error.\n"
#define ROGM  "ROGM Parameters syntax error.\n"
#define LOCK  "LOCK Not logged in.\n"
#define JESUS "JESUS Command OK.\n"
#define JUDA  "JUDA Connection will close.\n"
#define MATD  "MATD Internal server error.\n"
#define LOUC  "LOUC Successful command.\n"
#define JUDA  "JUDA Connection will close.\n"


#include <sys/select.h>
#include <uuid/uuid.h>
#include <time.h>

#define MAX_NAME_LENGTH         (32)
#define MAX_DESC_LENGTH         (255)
#define MAX_BODY_LENGTH         (512)
#define UUID_LENGTH             (36 + 1)
#define TIME_LENGTH             (40)


typedef struct __attribute__((packed)) msg_s {
    uuid_t user;
    time_t time;
    char content[MAX_BODY_LENGTH];
} msg_t;

typedef struct __attribute__((packed)) thread_s {
    char title[MAX_NAME_LENGTH];
    char content[MAX_BODY_LENGTH];
    uuid_t id;
    uuid_t user;
    time_t time;

    msg_t **messages;
} thread_t;

typedef struct __attribute__((packed)) chan_s {
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESC_LENGTH];
    uuid_t id;

    thread_t **threads;
} chan_t;

typedef struct __attribute__((packed)) team_s {
    char name[MAX_NAME_LENGTH];
    char desc[MAX_DESC_LENGTH];
    uuid_t id;
    uuid_t user;

    chan_t **channels;
} team_t;


typedef struct __attribute__((packed)) user_s {
    char username[MAX_NAME_LENGTH];
    uuid_t id;

    uuid_t team;
    uuid_t channel;
    uuid_t thread;

    uuid_t *subbed;
    msg_t **private;
} user_t;

typedef struct conn_s {
    user_t *user;
    int fd;
} conn_t;

typedef struct server_s {
    conn_t **conns; // connected
    user_t **regs;  // registered
    team_t **teams;

    fd_set active;
    fd_set read;
    fd_set write;
} server_t;

#define DECL_OP(x)                                  \
    void x(char *buf, conn_t *usr, server_t *srv);


DECL_OP(login);
DECL_OP(logout);
DECL_OP(subq);
DECL_OP(sub);
DECL_OP(unsub);
DECL_OP(uset);
DECL_OP(usec);
DECL_OP(usetr);
DECL_OP(create);
DECL_OP(list);
DECL_OP(info);
DECL_OP(hmes);
DECL_OP(user);
DECL_OP(users);
DECL_OP(mes);


#define USAGE "USAGE: ./myteams_server port\n"                          \
    "\tport  is the port number on which the server socket listens.\n"

char **split(char *buf);
char **parts_main(char *buf);
char **split_expect(char *buf, int fd, int expect);
void parse_msg(int fd, char *buf, server_t *srv);
char **split_expect_quoted(char *buf, int fd, int expect);

int chk_digit(char *str);

void accept_client(int sock, server_t *srv);
void register_client(int fd, server_t *srv);
int create_socket(int port, server_t *srv);

void loop(int socket, server_t *srv);


void save_regs(user_t **regs);
void save_teams(team_t **teams);
void restore_regs(server_t *srv);
void restore_teams(server_t *srv);

void write_messages(int fd, msg_t **msg);

team_t *find_team_id(uuid_t id, server_t *srv);
chan_t *find_chan_id(uuid_t id, team_t *team);
thread_t *find_thread_id(uuid_t id, chan_t *chan);
thread_t *get_current_thread(user_t *usr, server_t *srv);
int is_user_in_team(user_t *user, uuid_t team);

int is_user_connected(uuid_t id, server_t *srv);
conn_t *get_user_fd(server_t *srv, int fd);
void remove_client_fd(int fd, server_t *srv);
void remove_client(conn_t *usr, server_t *srv);

int init_team(team_t *team, char *name, char *desc, conn_t *fd);
int init_channel(chan_t *chan, char *name, char *desc, conn_t *fd);
int init_thread(thread_t *thread, char *title, char *body, conn_t *u);
int init_message(msg_t *msg, char *content, conn_t *u);

int g_team(conn_t *conn, server_t *srv);
int g_chan(conn_t *conn, server_t *srv);
int g_thread(conn_t *conn, server_t *srv);

user_t *find_user_id(uuid_t id, server_t *srv);

void broad_login(server_t *srv, user_t *usr);
void broad_logout(server_t *srv, user_t *usr);

void broad_team(team_t *team, conn_t *usr, server_t *srv);
void broad_chan(chan_t *chan, conn_t *usr, server_t *srv);
void broad_thread(thread_t *thr, conn_t *usr, server_t *srv);
void broad_reply(msg_t *msg, conn_t *usr, server_t *srv);

void append_team(server_t *srv, team_t *team);
void append_channel(team_t *team, chan_t *chan);
void append_thread(chan_t *chan, thread_t *thread);
void append_reply(thread_t *thr, msg_t *msg);

int check_auth(conn_t *usr, uuid_t team);
int ck_t(conn_t *usr, char *thr, server_t *srv);
int ck_c(conn_t *usr, char *chan, server_t *srv);
int ck_m(conn_t *usr, char *team, server_t *srv);
int ck_a(conn_t *usr);

int exist_team(char *name, server_t *srv);
int exist_cn(char *name, server_t *srv, user_t *user);
int exist_thr(char *name, server_t *srv, user_t *user);


#endif
