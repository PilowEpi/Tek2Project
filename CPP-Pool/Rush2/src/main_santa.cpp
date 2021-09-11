/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** main_santa
*/

#include <iostream>
#include "Santa.hpp"
#include "Client.hpp"

void warp(char **av)
{
    Santa santa;
    int sock = initsock(av[2]);
    std::string content;

    while (1) {
        content = rcvsock(sock);
        if (content == "END")
            exit(0);
        santa.setContent(content);
        santa.unpackIt();
        santa.putdownGift();
    }
}

int main(int ac, char **av)
{
    Santa santa;

    if (ac == 3 && av[1] == std::string("-w"))
        warp(av);
    if (ac == 1) {
        std::cerr << "Usage : " << av[0] << " gift.xml ..." << std::endl;
        return (84);
    }
    for (int x = 1; x < ac; x++) {
        santa.watchGift(av[x]);
        if (!santa.takeGift())
            break;
        santa.unpackIt();
        santa.putdownGift();
    }
    return (0);
}
