/*
** EPITECH PROJECT, 2020
** OOP Arcade
** File description:
** main
*/

#include <dlfcn.h>
#include <err.h>

#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <filesystem>

#include "error.hpp"
#include "arcade.hpp"
#include "carcade.hpp"
#include "game.hpp"
#include "shared.hpp"

int usage(void)
{
    std::cout << "ARCADE USAGE" << std::endl << std::endl;
    std::cout << "\t./arcade graphical_lib_path" << std::endl << std::endl;
    std::cout << "DESCRIPTION" << std::endl << std::endl;
    std::cout << "\tgraphical_lib_path\ta path to a dynamic library (same architecture as us, see documentation)" << std::endl;
    return (84);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return (usage());
    try {
        Arcade arcade(argv);
        arcade.start();
    } catch (ArcadeError const &e) {
        std::cerr << e.getComponent() << e.what() << std::endl;
        return (84);
    }
    return (0);
}
