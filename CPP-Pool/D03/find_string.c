/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int find_s(const string_t *this, const string_t *str, size_t pos)
{
    char *result = 0;

    if (strlen(this->str) < pos || (strlen(this->str) < strlen(str->str)))
        return (-1);
    result = strstr(&this->str[pos], str->str);
    for (int i = 0; this->str[i]; i++) {
        if (&this->str[i] == &result[0])
            return (i);
    }
    return (-1);
}

int find_c(const string_t *this, const char *str, size_t pos)
{
    char *result = 0;

    if (strlen(this->str) < pos || (strlen(this->str) < strlen(str)))
        return (-1);
    result = strstr(&this->str[pos], str);
    for (int i = 0; this->str[i]; i++) {
        if (&this->str[i] == &result[0])
            return (i);
    }
    return (-1);
}