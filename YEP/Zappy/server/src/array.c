/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** array utils
*/

#include <stdlib.h>

int append(void ***array, void *elem)
{
    int i = 0;
    void **holder;

    for (; (*array)[i] != 0; i++);
    holder = reallocarray(*array, i + 2, sizeof(void *));
    if (!*array)
        return (1);
    holder[i] = elem;
    holder[i + 1] = 0;
    *array = holder;
    return (0);
}

void rem(void **array, void *elem)
{
    int passed = 0;

    for (int i = 0; array[i] != 0; i++) {
        if (array[i] == elem)
            passed = 1;
        if (!passed)
            continue;
        array[i] = array[i + 1];
    }
}
