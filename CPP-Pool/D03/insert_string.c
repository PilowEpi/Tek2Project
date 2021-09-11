/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

void insert_c(string_t *this, size_t pos, const char *str)
{
    int size = strlen(this->str) + strlen(str) + 1;
    char *result =  malloc(size);
    size_t index = 0;
    size_t current = 0;

    memset(result, 0, size);
    for (; this->str[current] && current != pos; current++, index++)
        result[current] = this->str[current];
    for (int i = 0; str[i]; i++, current++)
        result[current] = str[i];
    for (;this->str[index]; index++, current++)
        result[current] = this->str[index];
    free(this->str);
    this->str = strdup(result);
    free(result);
}

void insert_s(string_t *this, size_t pos, const string_t *str)
{
    int size = strlen(this->str) + strlen(str->str) + 1;
    char *result =  malloc(size);
    size_t index = 0;
    size_t current = 0;

    memset(result, 0, size);
    for (; this->str[current] && current != pos; current++, index++)
        result[current] = this->str[current];
    for (int i = 0; str->str[i]; i++, current++)
        result[current] = str->str[i];
    for (;this->str[index]; index++, current++)
        result[current] = this->str[index];
    free(this->str);
    this->str = strdup(result);
    free(result);
}