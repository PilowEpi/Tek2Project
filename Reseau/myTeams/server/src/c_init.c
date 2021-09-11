/*
** EPITECH PROJECT, 2021
** teams
** File description:
** init structs
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"

int init_team(team_t *team, char *name, char *desc, conn_t *usr)
{
    if (strlen(name) + 1 >= MAX_NAME_LENGTH ||
        strlen(desc) + 1 >= MAX_DESC_LENGTH) {
        dprintf(usr->fd, ROGM);
        free(team);
        return (1);
    }
    memset(team, 0, sizeof(team_t));
    memset(team->name, 0, MAX_NAME_LENGTH);
    memset(team->desc, 0, MAX_DESC_LENGTH);
    strcpy(team->name, name);
    strcpy(team->desc, desc);
    uuid_generate_random(team->id);
    uuid_copy(team->user, usr->user->id);
    team->channels = calloc(1, sizeof(chan_t *));
    return (0);
}

int init_channel(chan_t *chan, char *name, char *desc, conn_t *usr)
{
    if (strlen(name) + 1 >= MAX_NAME_LENGTH ||
        strlen(desc) + 1 >= MAX_DESC_LENGTH) {
        dprintf(usr->fd, ROGM);
        free(chan);
        return (1);
    }
    memset(chan->name, 0, MAX_NAME_LENGTH);
    memset(chan->desc, 0, MAX_DESC_LENGTH);
    strcpy(chan->name, name);
    strcpy(chan->desc, desc);
    uuid_generate_random(chan->id);
    chan->threads = calloc(1, sizeof(thread_t *));
    return (0);
}

int init_thread(thread_t *thread, char *title, char *body, conn_t *usr)
{
    if (strlen(title) + 1 >= MAX_NAME_LENGTH ||
        strlen(body) + 1 >= MAX_BODY_LENGTH) {
        dprintf(usr->fd, ROGM);
        free(thread);
        return (1);
    }
    memset(thread->title, 0, MAX_NAME_LENGTH);
    memset(thread->content, 0, MAX_BODY_LENGTH);
    strcpy(thread->title, title);
    strcpy(thread->content, body);
    thread->time = time(0);
    uuid_copy(thread->user, usr->user->id);
    uuid_generate_random(thread->id);
    thread->messages = calloc(1, sizeof(msg_t *));
    return (0);
}

int init_message(msg_t *msg, char *content, conn_t *usr)
{
    if (strlen(content) + 1 >= MAX_BODY_LENGTH) {
        dprintf(usr->fd, ROGM);
        free(msg);
        return (1);
    }
    memset(msg->content, 0, MAX_BODY_LENGTH);
    strcpy(msg->content, content);
    msg->time = time(0);
    uuid_copy(msg->user, usr->user->id);
    return (0);
}
