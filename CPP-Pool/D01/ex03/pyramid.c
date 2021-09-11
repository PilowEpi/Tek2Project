/*
** EPITECH PROJECT, 2020
** pyramid.c
** File description:
** pyramid
*/

#include <stdio.h>
#include <stdlib.h>

int **alloc_map(int size)
{
    int **map = malloc(sizeof(int *) * size);

    if (!map) return (0);
    for (int i = 0; i < size; i++) {
        map[i] = malloc(sizeof(int) * (i + 1));
        if (!map[i]) return (0);
    }
    return (map);
}

void calculate_map(const int **map, int **result, int line)
{
    if (line == 0) {
        printf("%d\n", map[0][0]);
        result[0][0] = map[0][0];
        return;
    }

    for (int i = 0; i < line + 1; i++) {
        if (i == 0) {
            result[line][i] = map[line][i] + map[line - 1][i];
            printf(" 1: %d\n", result[line][i]);
            continue;
        }
        printf("%d ", result[line - 1][i - 1]);
        printf("> %d ?\n", result[line - 1][i]);
        printf(" ou %d ? %d\n", line, i);

        if ((result[line - 1][i - 1] > result[line - 1][i]) ||
            (line + 1) == i) {
            result[line][i] = map[line][i] + map[line - 1][i - 1];
            printf(" 2: %d\n",result[line][i]);

        } else {
            result[line][i] = map[line][i] + map[line - 1][i];
            printf(" 3: %d\n",result[line][i]);
        }
    }
}

int pyramid_patch(int size, const int **map)
{
    int **result = alloc_map(size);

    if (!result) return (0);
    for (int i = 0; i < size; i++) {
        calculate_map(map, result, i);
    }
    printf("%d %d %d %d\n", result[3][0], result[3][1],
    result[3][2], result[3][3]);
}

int main (void)
{
    const int a[] = {0};
    const int b[] = {7, 4};
    const int c[] = {2, 3, 6};
    const int d[] = {8, 5, 9, 3};

    const int *tab[] = {
        a, b, c, d
    };
    printf("%d", pyramid_patch(4, tab));
}