/*
** EPITECH PROJECT, 2020
** OOP Nanotekspice
** File description:
** main
*/

#include "Core.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (84);

    try {
        Core *core = new Core(argv[1]);
        delete core;
    } catch (NanoError const & e) {
        std::cerr << e.getComponent() << " :" << e.what();
        return (84);
    }
}