/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** write buffering
*/

#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "zappy.h"

void write_player(player_t *player, char *format, ...)
{
    char buffer[4096] = {0};
    va_list va;
    size_t len = 0;
    buf_t *buf = player->buf;

    va_start(va, format);
    len = vsnprintf(buffer, 4096, format, va);
    va_end(va);
    len += strlen(buf->write);
    if (len + 1 >= buf->w_buf_size) {
        buf->write = realloc(buf->write, len + 1);
        buf->w_buf_size = len + 1;
    }
    strcat(buf->write, buffer);
}

void write_buf(buf_t *buf, char *format, ...)
{
    char buffer[4096] = {0};
    va_list va;
    size_t len = 0;

    va_start(va, format);
    len = vsnprintf(buffer, 4096, format, va);
    va_end(va);
    len += strlen(buf->write);
    if (len + 1 >= buf->w_buf_size) {
        buf->write = realloc(buf->write, len + 1);
        buf->w_buf_size = len + 1;
    }
    strcat(buf->write, buffer);
}

void get_waiting(server_t *srv, fd_set **set)
{
    static fd_set *holder = 0;

    *set = 0;
    if (!*set && !holder) {
        holder = malloc(sizeof(fd_set));
        if (!holder)
            return;
    }
    FD_ZERO (holder);
    for (int i = 0; srv->conns[i]; i++) {
        if (srv->conns[i]->buf->write[0] && !*set)
            *set = holder;
        if (srv->conns[i]->buf->write[0])
            FD_SET(srv->conns[i]->buf->fd, *set);
    }
}

void attempt_flush(buf_t *buf)
{
    size_t b_len = strlen(buf->write);
    ssize_t written = write(buf->fd, buf->write, b_len);

    if (written < 0)
        return;
    memcpy(buf->write, buf->write + written, b_len - written);
    memset(buf->write + b_len - written, 0, written);
}

void flush_bufs(server_t *srv, fd_set *set)
{
    if (!set)
        return;
    for (int i = 0; srv->conns[i]; i++) {
        if (FD_ISSET(srv->conns[i]->buf->fd, set))
            attempt_flush(srv->conns[i]->buf);
    }
}
