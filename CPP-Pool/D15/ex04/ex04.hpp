/*
** EPITECH PROJECT, 2020
** CPOOL D15
** File description:
** CPOOL D15
*/

#ifndef EX04_HPP_
#define EX04_HPP_

template <typename T>
bool equal(const T &a, const T &b)
{
    if (a == b) return true;
    return false;
}

template <class T>
class Tester
{
    public:
        bool equal(const T &a, const T &b);
};

#endif