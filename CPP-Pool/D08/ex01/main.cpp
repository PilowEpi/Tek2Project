/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <iostream>
#include <string>
#include "Droid.hpp"
#include "DroidMemory.hpp"

void test_droid(void)
{
    Droid d("Cheh");
    DroidMemory mem;
    mem += 90;
    d.setBattleData(new DroidMemory(mem));
    std::cout << "LOL" << std::endl;
    std::cout << *d.getBattleData() << std::endl;
    std::cout << "LOL"<< std::endl;
}

int main (void)
{
    DroidMemory mem1;
    mem1 += 42;
    DroidMemory mem2 = mem1;
    std::cout << mem1 << std::endl;
    DroidMemory mem3;
    mem3 << mem1;
    mem3 >> mem1;
    mem3 << mem1;
    std::cout << mem3 << std::endl;
    std::cout << mem1 << std::endl;

    test_droid();
}