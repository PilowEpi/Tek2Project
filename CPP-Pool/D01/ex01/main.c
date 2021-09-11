/*
** EPITECH PROJECT, 2020
** z.c
** File description:
** z for ZorgClub
*/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "menger.h"

int recursive_menger(t_menger *data, int size)
{
    int resize = size / 3;

    if (resize < 1 && data->level == 1)
        return (0);
    printf("%03d %03d %03d\n", resize, data->x, data->y);
    if (resize == 1 || data->level == 1)
        return (0);
    for (int column = -1; column < 2; column++) {
        data->x += resize * column + (resize / 3);
        for (int row = -1; row < 2; row++) {
            data->y += resize * row + (resize / 3);
            if (!(column == 0 && row == 0)) recursive_menger(data, resize);
            data->y -= resize * row + (resize / 3);
        }
        data->x -= resize * column + (resize / 3);
    }
}

int parse_args(int ac, char **args)
{
    if (ac != 3) return (84);
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (!isdigit(args[1][i]))
            return (84);
    }
    for (int i = 0; args[2][i] != '\0'; i++) {
        if (!isdigit(args[2][i]))
            return (84);
    }
    if (atoi(args[1]) <= 0 || atoi(args[2]) < 0 || atoi(args[1]) % 3 != 0) {
        return (84);
    }
    return (0);
}

int main(int ac, char **args)
{
    int size = 0;
    int level = 0;
    t_menger *data = 0;

    if (parse_args(ac, args) == 84) return (84);

    data = malloc(sizeof(t_menger));
    if (!data) return (84);
    data->size = atoi(args[1]);
    data->level = atoi(args[2]);
    data->x = data->size / 3;
    data->y = data->size / 3;
    recursive_menger(data, data->size);
    return (0);
}