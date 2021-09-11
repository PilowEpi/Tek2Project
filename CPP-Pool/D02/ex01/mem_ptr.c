/*
** EPITECH PROJECT, 2020
** mem_ptr.c
** File description:
** mem_ptr
*/

#include <stdlib.h>
#include <string.h>

#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    int size = strlen(str1) + strlen(str2) + 1;

    *res = malloc(size);
    memset(*res, 0, size);
    strcat(*res, str1);
    strcat(*res, str2);
}

void add_str_struct(str_op_t *str_op)
{
    char *str1 = str_op->str1;
    char *str2 = str_op->str2;
    int size = strlen(str1) + strlen(str2) + 1;

    str_op->res = malloc(size);
    memset(str_op->res, 0, size);
    strcat(str_op->res, str1);
    strcat(str_op->res, str2);
}