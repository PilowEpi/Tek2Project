/*
** EPITECH PROJECT, 2020
** func_ptr.c
** File description:
** func_ptr
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_reverse(const char *str)
{
    for (int i = strlen(str) - 1; i >= 0; i--)
        printf("%c", str[i]);
    printf("\n");
}

void print_upper(const char *str)
{
    int j = 0;
    char result[strlen(str)+1];

    memset(result, 0, strlen(str) + 1);
    for (int i = 0; i <= strlen(str); i++) {
        result[j] = (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 32 : str[i];
        j++;
    }
    printf("%s\n", result);
}

void print_42(const char *str)
{
    void *address = (void *)str;
    printf("42\n");
}

void do_action(action_t action, const char *str)
{
    void (*function[])(const char *str) = {
        &print_normal,
        &print_reverse,
        &print_upper,
        &print_42};

    (function[action])(str);
}