/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice bonus
*/

#include <wordexp.h>
#include <stdio.h>

#include "array.h"
#include "list.h"
#include "int.h"
#include "function.h"
#include "new.h"
#include "product.h"
#include "shopping.h"

Object *get_functions(void)
{
    Object *functions = new(Array, 6,Function, NULL);
    setitem(functions, 0, &add);
    setitem(functions, 1, &del);
    setitem(functions, 2, &change);
    setitem(functions, 3, &help);
    setitem(functions, 4, &show);
    setitem(functions, 5, &dellast);
    return functions;
}

int is_command(char *cmd)
{
    const char *cmd_list[] = {
        "add", // Take name count priority
        "del", // Take name
        "change", // Take name <value value value>
        "help", // None see some help
        "show", // Show
        "dellast", // Delete last in list
    };

    for (size_t i = 0; i < sizeof(cmd_list) / sizeof(cmd_list[0]); i++) {
        if (strcmp(cmd_list[i], cmd) == 0) {
            return i;
        }
    }
    return -1;
}

int exec_command(Object *list, Object *f, size_t ac, char **args)
{
    int (*exec)(Object *, size_t ac, char **) = get(f);
    return exec(list, ac, args);
}

int find_command(Object *list, size_t ac, char **av)
{
    int cmd = -1;
    if (ac == 0) return 0;
    if ((cmd = is_command(av[0])) == -1) {
        printf("%s is not a command\n", av[0]);
        return 0;
    }
    Object *functions = get_functions();
    Object *to_exec = getitem(functions, cmd);
    if (!to_exec) raise("Function not initialized\n");
    cmd = exec_command(list, to_exec, ac, av);
    delete(functions);
    return 0;
}

int prepare_command(Object *list, char *command)
{
    wordexp_t p;
    char **av;
    int value = 0;
    if (wordexp(command, &p, WRDE_SHOWERR) == 0)
        value = find_command(list, p.we_wordc, p.we_wordv);
    wordfree(&p);
    return value;
}

int main_shopping(void)
{
    char *command = NULL;
    int read = 0;
    size_t len = 0;
    int end = 0;
    Object *list = new(List, 0, Product, "str");

    while (!end) {
        printf("Shopping >");
        read = getline(&command, &len, stdin);
        if (read == -1)
            return 0;
        command[strlen(command) - 1] = '\0';
        end = prepare_command(list, command);
    }
}