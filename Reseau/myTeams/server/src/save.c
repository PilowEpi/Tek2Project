/*
** EPITECH PROJECT, 2021
** server
** File description:
** save
*/

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "server.h"

void write_messages(int fd, msg_t **msg)
{
    int n_msg = 0;

    for (; msg[n_msg]; n_msg++);
    write(fd, &n_msg, sizeof(n_msg));
    for (int i = 0; i < n_msg; i++)
        write(fd, msg[i], sizeof(msg_t));
}

void write_user(int fd, user_t *usr)
{
    int n_sub = 0;

    for (; !uuid_is_null(usr->subbed[n_sub]); n_sub++);
    write(fd, usr, sizeof(user_t));
    write(fd, &n_sub, sizeof(n_sub));
    for (int i = 0; i < n_sub; i++)
        write(fd, usr->subbed[i], sizeof(uuid_t));
    write_messages(fd, usr->private);
}

void save_regs(user_t **regs)
{
    int fd = 0;
    int i = 0;
    struct stat st = {0};

    for (; regs[i]; i++);
    if (stat("data", &st) == -1)
        mkdir("data", 0700);
    fd = open("data/users.dat", O_WRONLY | O_CREAT | O_TRUNC, 0664);
    write(fd, &i, sizeof(i));
    for (int j = 0; j < i; j++)
        write_user(fd, regs[j]);
}
