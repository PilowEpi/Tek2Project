/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** error check
*/

#include <ctype.h>

int is_numeric(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (!isdigit(str[i]))
            return (0);
    }
    return (1);
}
