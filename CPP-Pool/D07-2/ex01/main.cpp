/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"
#include <string>
#include <iostream>

int main()
{
    KoalaBot bot;
    const KoalaBot bot2;

    bot2.informations();

    bot.informations();

    std::cout << std::boolalpha << bot.status () << std :: endl ;
    Head h("A-112", 0);
    bot.swapParts(h);
    h.informations();
    bot.informations();
    std::cout << std::boolalpha << bot.status () << std :: endl ;

    Legs l("L-112", 0);
    bot.setParts(l);
    bot.informations();
    l.informations();
    std::cout << std::boolalpha << bot.status () << std :: endl ;
    return 0;
}