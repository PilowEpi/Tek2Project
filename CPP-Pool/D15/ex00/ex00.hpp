/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template <typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T min(T a, T b)
{
    return (a == b) ? a : (a < b) ? a : b;
}

template<typename T>
T max(T a, T b)
{
    return (a == b) ? a : (a > b) ? a : b;
}

template<typename T>
T add(T a, T b)
{
    return a + b;
}


#endif /* EX00_HPP_ */