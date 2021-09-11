/*
** EPITECH PROJECT, 2020
** add_mul.c
** File description:
** add_mul
*/

#include "mem_ptr.h"

static void test_add_str ( void )
{
    char *str1 = "Hey, ";
    char *str2 = "it works !";
    char *res ;
    add_str (str1, str2, &res ) ;
    printf ("%s\n", res ) ;
}

static void test_add_str_struct ( void )
{
    char * str1 = "Hey, ";
    char * str2 = "it works !";

    str_op_t str_op ;
    str_op . str1 = str1 ;
    str_op . str2 = str2 ;
    add_str_struct (& str_op ) ;
    printf ("%s\n", str_op . res ) ;
}

int main ( void )
{
    test_add_str () ;
    test_add_str_struct () ;
    return (0) ;
}