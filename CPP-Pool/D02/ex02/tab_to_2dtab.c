/*
** EPITECH PROJECT, 2020
** tabto2dtab.c
** File description:
** tabto2dtab
*/

#include <stdlib.h>

void tab_to_2dtab(const int *tab, int length, int width, int ***res)
{
    int postion = 0;
    int **result = malloc(sizeof(int *) * length);

    for (int i = 0; i < length; i++) {
        result[i] = malloc(sizeof(int) * width);
        for (int j = 0; j < width; j++)
            result[i][j] = tab[postion++];
    }
    *res = result;
}