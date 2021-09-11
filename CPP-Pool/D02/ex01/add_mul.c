/*
** EPITECH PROJECT, 2020
** add_mul.c
** File description:
** add_mul
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    int result_sum = first + second;
    int result_product = first * second;

    *sum = result_sum;
    *product = result_product;
}

void add_mul_2param(int *first, int *second)
{
    int result_sum = *first + *second;
    int result_product = *second * *second;

    *first = result_sum;
    *second = result_product;
}