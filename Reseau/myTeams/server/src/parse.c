/*
** EPITECH PROJECT, 2021
** teams
** File description:
** parsing
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "server.h"

char **parts_quoted(char *buf)
{
    char **res = malloc(sizeof(char *) * 2);
    char delim[] = "\"";
    char *ptr = strtok(buf, delim);
    size_t i = 2;

    res[0] = ptr;
    res[1] = 0;
    while (ptr != NULL) {
        ptr = strtok(NULL, delim);
        res = reallocarray(res, i + 1, sizeof(char *));
        res[i - 1] = ptr;
        res[i] = 0;
        i++;
    }
    return (res);
}

char **split_quoted(char *msg)
{
    char **split = parts_quoted(msg);
    char **res = 0;
    size_t n = 0;
    size_t memb = 0;

    for (; split[n]; n++);
    if (n % 2 != 0) {
        free(split);
        return (0);
    }
    memb = 1 + n / 2 + 1;
    res = calloc(memb, sizeof(char *));
    res[0] = split[0];
    for (int i = 1; i < memb; i++)
        res[i] = split[i * 2 - 1];
    res[memb - 1] = 0;
    free(split);
    return (res);
}

char **split_expect_quoted(char *buf, int fd, int expect)
{
    char **res = split_quoted(buf);
    size_t i = 0;

    for (; res && res[i] != 0; i++);
    if (i == expect)
        return (res);
    free(res);
    dprintf(fd, ROGM);
    return (0);
}

char **parts_main(char *buf)
{
    char **res = malloc(sizeof(char *) * 2);
    char delim[] = "\n";
    char *ptr = strtok(buf, delim);
    size_t i = 2;

    res[0] = ptr;
    res[1] = 0;
    while (ptr != NULL) {
        ptr = strtok(NULL, delim);
        res = reallocarray(res, i + 1, sizeof(char *));
        res[i - 1] = ptr;
        res[i] = 0;
        i++;
    }
    return (res);
}
