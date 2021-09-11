/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** header
*/

#ifndef _ZAPPY_H
#define _ZAPPY_H

#define USAGE ""                                                        \
    "Usage: ./zappy_server -p port -x width -y height -n name1 "        \
    "name2 ... -c clientsNb -f freq\n"                                  \
    "      port      is the port number\n"                              \
    "      width     is the width of the world\n"                       \
    "      height    is the height of the world\n"                      \
    "      nameX     is the name of the team X\n"                       \
    "      clientsNb is the number of authorized clients per team\n"    \
    "      freq      is the reciprocal of time unit for execution"      \
    " of actions\n"                                                     \

#include <sys/select.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

static const double item_density[] = {
    0.5,
    0.3,
    0.15,
    0.1,
    0.1,
    0.08,
    0.05
};

typedef struct secret_s {
    uint8_t nb;
    uint8_t linemate;
    uint8_t deraumere;
    uint8_t sibur;
    uint8_t mendiane;
    uint8_t phiras;
    uint8_t thystame;
} secret_t;

static const secret_t secret[] = {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1},
};

enum player_status {
    PENDING,
    PLAYER,
    GUI
};

enum items_type {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

#define GUI_MAGIC ("ZAPPY_GUI")


#define GET_ITEM_TYPE(x, i)                \
    (( (uint16_t) *( (char *) &x + i * 2) ))

#define ADD_ITEM_TYPE(x, i, qty)                \
    *((uint16_t *) ((char *) &x + i * 2) ) = qty + GET_ITEM_TYPE(x, i)

#define REM_ITEM_TYPE(x, i, qty)                   \
    ADD_ITEM_TYPE(x, i, -qty)

typedef struct buf_s {
    int fd;

    size_t r_buf_size;
    size_t w_buf_size;

    char *read;
    char *write;
} buf_t;


typedef struct server_s server_t;
typedef struct team_s team_t;
typedef struct player_s player_t;

typedef struct event_s {
    uint8_t status : 1;
    struct timespec date;
    player_t *player;
    uint8_t type;
    uint16_t limit;
    char *msg;

    void (*exec)(struct event_s *);
} event_t;

struct player_s {
    uint8_t status;

    uint8_t vision;
    uint8_t rotation;
    uint32_t x;
    uint32_t y;

    uint16_t food;
    uint16_t linemate;
    uint16_t deraumere;
    uint16_t sibur;
    uint16_t mendiane;
    uint16_t phiras;
    uint16_t thystame;

    server_t *srv;

    struct timespec death;

    buf_t *buf;
    event_t evs[10];
};


typedef struct _u128 {
    uint64_t a;
    uint64_t b;
} u128;


struct team_s {
    uint64_t size_left;
    uint64_t egg_match;
    uint64_t egg_id;
    u128 **eggs;

    char *name;
    player_t **players;
};


struct server_s {
    uint8_t freq;
    uint16_t max_cli;
    uint16_t port;
    uint32_t width;
    uint32_t height;

    uint32_t max_fd;
    fd_set read;
    fd_set active;

    player_t **players;
    player_t **guis;
    player_t **conns;
    team_t **teams;
    u128 **items;

    event_t **s_evs;
};


server_t *init_server(void);
void alloc_map(server_t *srv);
void fill_map(server_t *);

void create_teams(char **names, server_t *server);

int is_numeric(char *);
int handle2(int *idx, int ac, char **av, server_t *server);
int handle_args(int ac, char **av, server_t *server);

int append(void ***array, void *elem);
void rem(void **array, void *elem);

void loop(int socket, server_t *server);

player_t *register_client(int fd, server_t *srv);
void set_player_coord(player_t *player);

void flush_bufs(server_t *srv, fd_set *set);
void get_waiting(server_t *srv, fd_set **set);
void write_player(player_t *player, char *format, ...);
void write_buf(buf_t *buf, char *format, ...);

void get_next_event(server_t *srv, struct timespec **);

void flush_input(char *cmd, buf_t *buf, server_t *srv);

void accept_client(int socket, server_t *srv);
void remove_client(int fd, server_t *srv);
buf_t *get_buf_by_fd(int fd, server_t *srv);
player_t *get_player_by_fd(int fd, server_t *srv);

team_t *get_team_by_name(char *name, server_t *srv);
team_t *get_team_by_player(player_t *player, server_t *srv);
int is_player_in_team(player_t *player, team_t *team);

event_t *create_server_event(uint16_t limit, server_t *srv,
    void (*ptr)(event_t *));

event_t *create_event(uint16_t limit, player_t *player,
    void (*ptr)(event_t *));
int is_event_closer(struct timespec *d1, struct timespec *d2);

void handle_events(server_t *srv);
void set_food(server_t *srv);

int item_to_enum(char *item);
void rem_from_inventory(int type, player_t *player, int qty);
void add_to_inventory(int type, player_t *player, int qty);
int get_from_inventory(int type, player_t *player);

void print_at(player_t *pl, int i, int j);
void move(player_t *player, int rot);
void do_elevate(server_t *srv, player_t *pl);
int incantation_check(server_t *srv, player_t *pl);

int case_id(player_t *psrc, player_t *pdest, int with, int height);

int get_id(player_t *pl);

int is_event_closer(struct timespec *d1, struct timespec *d2);
struct timespec get_closest_event_player(player_t *player);
struct timespec ticks(player_t *pl);
struct timespec ticks_to_spec(int ticks, server_t *srv);
int spec_to_ticks(struct timespec spec, server_t *srv);
void add_spec(struct timespec *d1, struct timespec d2);
void to_delay(struct timespec *date);
void delay(struct timespec *d1, struct timespec *d2);


#define DCL_EV(x)                               \
    void x(char *, player_t *);                 \
    void do_ ## x(event_t *);

DCL_EV(forward);
DCL_EV(right);
DCL_EV(left);
DCL_EV(look);
DCL_EV(inventory);
DCL_EV(broadcast);
DCL_EV(connect_nb);
DCL_EV(xfork);
DCL_EV(hatch);
DCL_EV(eject);
DCL_EV(take);
DCL_EV(set);
DCL_EV(incantation);
DCL_EV(ko);

#define DCL_UI(x)                               \
    void x(char *, player_t *);

DCL_UI(msz);
DCL_UI(bct);
DCL_UI(mct);
DCL_UI(tna);
DCL_UI(ppo);
DCL_UI(plv);
DCL_UI(pin);
DCL_UI(sgt);
DCL_UI(sst);

void send_players(player_t *gui);

void broad_connect(player_t *pl);
void broad_eject(player_t *pl);
void broad_bcast(player_t *pl, char *msg);
void broad_death(player_t *pl);
void broad_set(player_t *pl, int type);
void broad_take(player_t *pl, int type);
void broad_istart(player_t *pl);
void broad_iend(player_t *pl, int res);
void broad_fwd(player_t *pl);
void broad_rotate(player_t *pl);
void broad_level(player_t *pl);
void broad_inv(player_t *pl);
void broad_die(player_t *pl);
void broad_place(server_t *srv, int x, int y);
void broad_food(player_t *pl);
void broad_egg(player_t *pl, int egg_id);
void broad_hatch(player_t *pl, int egg_id);

#endif
