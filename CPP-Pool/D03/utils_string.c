/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <string.h>
#include <stdlib.h>
#include "string.h"

int to_int(const string_t *this)
{
    return (atoi(this->str));
}