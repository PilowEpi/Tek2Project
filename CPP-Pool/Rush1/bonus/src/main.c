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

void show_container(Object *list)
{
    Object  *itl = begin(list);

    printf("Len : %lu\n", len(list));
    for (size_t i = 0; i < len(list); i++) {
        char *strlist = str(getval(itl));
        printf("%s\n", strlist);
        free(strlist);
        incr(itl);
    }
    delete(itl);
}

void compare_list(Object *array, Object *list)
{
    Object  *it = begin(array);
    Object  *it_end = end(array);
    Object  *itl = begin(list);
    Object  *itl_end = end(list);

    printf("Size : Array : %zu | List : %zu\n", len(array), len(list));
    for (size_t i = 0; i < 10; i++) {
        char *str = str(getval(it));
        char *strlist = str(getval(itl));
        printf("Value : %s | %s\n", str, strlist);
        free(str);
        free(strlist);
        incr(it);
        incr(itl);
    }
    delete(it);
    delete(it_end);
    delete(itl);
    delete(itl_end);
}

void simple_test(void)
{
    Object  *list = new(List, 10, Int, 5);
    Object  *array = new(Array, 10, Int, 5);
    Object  *it = begin(array);
    Object  *it_end = end(array);
    Object  *itl = begin(list);
    Object  *itl_end = end(list);

    compare_list(array, list);
    printf("______________________\n");
    setitem(list, 5, 12);
    setitem(array, 5, 12);
    compare_list(array, list);
    printf("______________________\n");
    
    setitem(list, 6, 13);
    setitem(array, 6, 13);
    compare_list(array, list);
    printf("______________________\n");
    
    setval(it, 123);
    setval(itl, 123);
    compare_list(array, list);
    printf("______________________\n");
    
    delete(itl);
    delete(itl_end);
    delete(list);
    delete(it);
    delete(it_end);
    delete(array);
}

void bonus_container(void)
{
    Object *array = new(Array, 10, Int, 5);
    show_container(array);
    resize(array, 5, 4);
    show_container(array);
    resize(array, 15, 100);
    show_container(array);
    delete(array);

    Object *list = new(List, 10, Int, 5);
    show_container(list);
    setitem(list, 9, 122);
    show_container(list);
    pop_back(list);
    show_container(list);
    setitem(list, 5, 122);
    show_container(list);
    pop_at(list, 5);
    show_container(list);
    push_back(list, 42);
    push_back(list, 43);
    push_back(list, 44);
    show_container(list);
    delete(list);
}

void bonus_class(void)
{
    Object *product = new(Product, "Machine a laver", 1, 1);
    char *str = str(product);
    printf("%s\n", str);
    printf("%s\n", get(product));
    Object *function = new(Function, &bonus_container);
    void (*func)(void) = get(function);
    printf("La partie en rouge proviens du pointeur sur fonction de l'objet Function\n");
    printf("\x1B[31m");
    func();
    printf("\x1B[0m");
}

void bonus_test(void)
{
    bonus_container();
    bonus_class();
}

void main_test(void)
{
    simple_test();
    bonus_test();
}

int main(int ac, char **av)
{
    if (ac > 1 && strcmp(av[1], "test") == 0) {
        main_test();
    } else {
        main_shopping();
    }
}