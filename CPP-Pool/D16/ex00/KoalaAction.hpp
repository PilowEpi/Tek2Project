/*
** EPITECH PROJECT, 2020
** CPOOL D16
** File description:
** CPOOL D16
*/


#ifndef KOALA_ACTION_HPP_
#define KOALA_ACTION_HPP_

#include <iostream>
#include <string>

class KoalaAction 
{
    public:
    KoalaAction() = default;

    void eat(const std::string &p) {
        std::cout << "I go to: " << p << std::endl;
    }

    void goTo( const std::string &p) {
        std::cout << "I eat: " << p << std::endl;
    }

    void reproduce(const std::string &p) {
        std::cout << "I attempt to reproduce with: " << p << std::endl;
    }

    void sleep( const std::string &p) {
        std::cout << "I sleep, and dream of: " << p << std::endl;
    }
}; 

#endif