/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** main select loop
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <err.h>

#include "zappy.h"

void parse(char *data, buf_t *buf, server_t *srv)
{
    size_t len = strlen(data) + strlen(buf->read);
    char *ptr = 0;
    char dup[4096] = {0};
    size_t cmd_len = 0;
    size_t left = 0;
    if (len > buf->r_buf_size) {
        buf->read = realloc(buf->read, len + 1);
        memset(buf->read + buf->r_buf_size, 0, len - buf->r_buf_size + 1);
        buf->r_buf_size = len + 1;
    }
    strcat(buf->read, data);
    while (ptr = strchr(buf->read, '\n')) {
        cmd_len = ptr - buf->read + 1;
        memset(dup, 0, 4096);
        memcpy(dup, buf->read, cmd_len);
        flush_input(dup, buf, srv);
        left = strlen(buf->read) - cmd_len;
        memcpy(buf->read, buf->read + cmd_len, left);
        memset(buf->read + left, 0, cmd_len);
    }
}

void read_client(buf_t *buf, server_t *srv)
{
    char buffer[1024] = {0};
    ssize_t nbytes;

    if (!buf)
        errx(84, "client not found");
    nbytes = read(buf->fd, buffer, 1023);
    if (nbytes <= 0)
        remove_client(buf->fd, srv);
    else
        parse(buffer, buf, srv);
}

void handle_set(int socket, server_t *srv)
{
    buf_t *buf = 0;

    if (FD_ISSET(socket, &srv->read))
        accept_client(socket, srv);
    for (int i = 0; i < srv->max_fd; i++) {
        if (FD_ISSET(i, &srv->read) && i != socket) {
            buf = get_buf_by_fd(i, srv);
            read_client(buf, srv);
        }
    }
}

void loop(int socket, server_t *srv)
{
    struct timeval *timeout = 0;
    fd_set *write_fds = 0;

    FD_ZERO (&srv->active);
    FD_SET (socket, &srv->active);
    srv->max_fd = socket + 1;
    while (1) {
        srv->read = srv->active;
        get_next_event(srv, (struct timespec **) &timeout);
        get_waiting(srv, &write_fds);
        if (select(srv->max_fd, &srv->read, write_fds, 0, timeout) < 0)
            errx(84, "select");
        fill_map(srv);
        set_food(srv);
        handle_set(socket, srv);
        handle_events(srv);
        flush_bufs(srv, write_fds);
    }
}
