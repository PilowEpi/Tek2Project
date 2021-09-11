/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX02_HPP_
#define EX02_HPP_

#include <iostream>

template <typename T>
T min(T a, T b)
{
    std::cout << "template min" << std::endl;
    return (a == b) ? a : (a < b) ? a : b;
}

template <typename T, typename U>
U templateMin(U *array, T size)
{
    U value = array[0]; 
    U tmp;
    for (T i = 0; i < size - 1; i++) {
        tmp = ::min(array[i], array[i + 1]);
        if (tmp < value)
            value = tmp;
    }
    return (value);
}

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    return (a == b) ? a : (a < b) ? a : b;
}

template <typename T = int [], typename U = int>
int nonTemplateMin(int array[], int size)
{
    int value = array[0];
    int tmp;
    for (int i = 0; i < size - 1; i++) {
        tmp = ::min(array[i], array[i + 1]);
        if (tmp < value)
            value = tmp;
    }
    return (value);
}

#endif