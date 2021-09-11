/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    int size = strlen(this->str) + strlen(ap->str) + 1;
    char *new_s = malloc(size);

    memset(new_s, 0, size);
    new_s = strcat(new_s, this->str);
    new_s = strcat(new_s, ap->str);
    free(this->str);
    this->str = strdup(new_s);
    free(new_s);
}

void append_c(string_t *this, const char *ap)
{
    int size = strlen(this->str) + strlen(ap) + 1;
    char *new_s = malloc(size);

    memset(new_s, 0, size);
    new_s = strcat(new_s, this->str);
    new_s = strcat(new_s, ap);
    free(this->str);
    this->str = strdup(new_s);
    free(new_s);
}