/*
** EPITECH PROJECT, 2020
** add_mul.c
** File description:
** add_mul
*/

#include "add_mul.h"

static void test_4_params(void)
{
    int first = 5;
    int second = 6;
    int sum;
    int product;

    add_mul_4param(first, second, &sum, &product);
    printf("%d + %d = %d\n", first, second, sum);
    printf("%d * %d = %d\n", first, second, product);
}

static void test_2_params(void)
{
    int first = -5;
    int second = 6;
    int add_res = first ;
    int mul_res = second ;

    add_mul_2param (&add_res , &mul_res);
    printf ("%d + %d = %d\n", first , second , add_res ) ;
    printf ("%d * %d = %d\n", first , second , mul_res ) ;
}

int main (void)
{
    test_4_params();
    test_2_params();
}