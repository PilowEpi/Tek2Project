/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

char at(string_t *this, size_t pos)
{
    if (strlen(this->str) > pos)
        return (this->str[pos]);
    return (-1);
}

void clear(string_t *this)
{
    memset(this->str, 0, strlen(this->str));
}

int size(const string_t *this)
{
    if (!this->str)
        return (-1);
    return (strlen(this->str));
}