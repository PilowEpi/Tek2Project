/*
** EPITECH PROJECT, 2020
** CPOOL D17
** File description:
** CPOOL D17
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator do_find(T &vect, int index)
{
    return (std::find(std::begin(vect), std::end(vect), index));
}

#endif