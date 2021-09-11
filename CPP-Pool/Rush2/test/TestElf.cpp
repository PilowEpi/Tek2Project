/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include "Test.hpp"
#include "Object.hpp"
#include "Toy.hpp"
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "IElf.hpp"
#include "PapaXmasElf.hpp"
#include "ConveyorBeltRand.hpp"
#include "TableRand.hpp"

Test(All, Test_Elf)
{
    Box obj;
    LittlePony p("UNICORN!");
    Teddy b("BEAR");
    std::cout << obj << std::endl;
    std::cout << p;
    std::cout << b;

    {
        IElf *lf = new PapaXmasElf;
        while (lf->wrap()) {
        	std::cout << "+1 gift wrapped !!" << std::endl;
        }
        delete lf;
    }
    {
        IElf *lf = new PapaXmasElf;
        lf->setTable(new TableRand);
        lf->setConveyor(new ConveyorBeltRand);
        while (lf->wrap()) {
            std::cout << "+1 gift wrapped !!" << std::endl;
        }
        delete lf;
    }
}
    