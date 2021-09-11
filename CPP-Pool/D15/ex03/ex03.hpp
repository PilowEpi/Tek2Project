/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX03_HPP_
#define EX03_HPP_

#include <string>
#include <iostream>

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

template <typename T, typename U>
void foreach(const T *elem, void (*func) (const T&elem), U size)
{
    for (U i = 0; i < size; i++)
        (*func)(elem[i]);
}

#endif