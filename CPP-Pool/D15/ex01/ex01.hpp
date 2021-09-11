/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <string.h>

template <typename T>
int compare(const T& a, const T& b)
{
    if ( a == b ) return 0;
    if ( a < b ) return -1;
    return 1;
}

template <typename T>
int compare(const char *a, const char *b)
{
    int result = strcmp(a, b);
    if ( result == 0 ) return 0;
    if ( result < 0 ) return -1;
    return 1;
}

#endif