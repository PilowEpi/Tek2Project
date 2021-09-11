/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice bonus
*/

#include <stdio.h>
#include "array.h"
#include "list.h"
#include "function.h"
#include "new.h"

int add(Object *list, size_t ac, char **args)
{
	char *name = NULL;
	int count = 0;
	int priority = 0;
	if (ac == 1) return 0;
	if (ac > 1)
		name = args[1];
	if (ac > 2)
		count = atoi(args[2]);
	if (ac > 3)
		priority = atoi(args[3]);
	Object  *itl = begin(list);
	for (size_t i = 0; i < len(list); i++) {
	    char *strlist = get(getval(itl));
	    if (strstr(strlist, args[1]) != NULL) {
	    	return 0;
	    }
	    incr(itl);
	}
    push_back(list, name, (size_t) count, (size_t) priority);
}

int del(Object *list, size_t ac, char **args)
{
    Object  *itl = begin(list);

    if (ac > 1) {
	    for (size_t i = 0; i < len(list); i++) {
	        char *strlist = get(getval(itl));
	        if (strstr(strlist, args[1]) != NULL) {
	        	pop_at(list, i);
	        	return 0;
	        }
	        incr(itl);
	    }
	}
}

int dellast(Object *list, size_t ac, char **args)
{
    pop_back(list);
    return 0;
}

int change(Object *list, size_t ac, char **args)
{
	if (ac > 2) { 
		del(list, ac, args);
		add(list, ac - 1, args + 1);
	}
}

int help(Object *list, size_t ac, char **args)
{
    list = list;
    ac = ac;
    args = args;
    printf("Commands : \n");
    printf("add : NAME, QUANTITY, PRIORITY | ajoute un produit\n");
    printf("del : NAME | supprimer le produit s'appelant NAME\n");
    printf("dellast : | supprime le dernier element de la liste de produit\n");
    printf("show : | affiche la liste des produits\n");
    printf("help : | affiche cette aide\n");
}

int show(Object *list, size_t ac, char **args)
{
    Object  *itl = begin(list);

    printf("len : %lu\n", len(list));
    for (size_t i = 0; i < len(list); i++) {
        char *strlist = str(getval(itl));
        printf("%s\n", strlist);
        free(strlist);
        incr(itl);
    }
    delete(itl);
}