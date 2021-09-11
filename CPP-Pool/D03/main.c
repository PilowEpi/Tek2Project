/*
** EPITECH PROJECT, 2020
** libstring
** File description:
** funct libstring
*/

#include <stdio.h>
#include "string.h"

int main(void)
{
    string_t s;
    string_init(&s, "Hello"); 

    printf("[%d]\n", s.find_c(&s, "lo", 2));
    string_destroy(&s);

    /*
    char *test = malloc(3);

    memset(test, 0, 3);
    string_init(&s, "Hello world"); 
    printf("%s\n", s.str);
    append_c(&s, "Hello world !");
    printf("%s\n", s.str);
    printf("%d\n", s.size(&s));
    printf("at : %d '%c'\n", s.at(&s, 0), s.at(&s, 0));
    printf("comp :%c\n", s.compare_c(&s, "Hello world"));
    printf("%s\n", s.c_str(&s));
    printf("%ld\n", s.copy(&s, test, 3, 3));
    printf("%s\n", test);
    printf("%d\n", s.empty(&s));
    printf("find : %d\n", s.find_c(&s, "wDrld", 0));
    s.insert_c(&s, 100, "XXXX");
    printf("insert : %s\n", s.str);
    free(test);
    string_destroy(&s);
    return (0);
    */
}