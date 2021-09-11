/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int compare_s(const string_t *this, const string_t *str)
{
    return (strcmp(this->str, str->str));
}

int compare_c(const string_t *this, const char *str)
{
    return (strcmp(this->str, str));
}

size_t copy(const string_t *this, char *s, size_t n, size_t pos)
{
    int copied_char = 0;
    char *temp = 0;

    if (pos > strlen(this->str))
        return (0);
    temp = this->str + pos;
    for (size_t i = 0; i < n && i < (strlen(temp) + 1); pos++, i++) {
        s[i] = temp[i];
        copied_char++;
    }
    return (copied_char);
}

const char *c_str(const string_t *this)
{
    return (this->str);
}

int empty(const string_t *this)
{
    if (!strlen(this->str))
        return (1);
    return (0);
}