/*
** EPITECH PROJECT, 2021
** Rush2
** File description:
** main
*/

#include <unistd.h>
#include "Teddy.hpp"
#include "LittlePony.hpp"
#include "Box.hpp"
#include "GiftPaper.hpp"
#include "IElf.hpp"
#include "PapaXmasElf.hpp"
#include "ConveyorBeltRand.hpp"
#include "TableRand.hpp"
#include "MagicalCarpet.hpp"

Object *MyUnitTests(Object **objs)
{
    objs[0]->wrapMeThat(objs[1]);
    objs[1]->wrapMeThat(objs[2]);
    return (objs[2]);
}

int testBox (void)
{
    Teddy ted;
    Box box;
    GiftPaper gf;

    Object *obj[4] = {&ted, &box, &gf, 0};
    MyUnitTests(obj);
    return 0;
}

void mine_little_pony()
{
    std::cout << "~~~~ Little Pony and Teddy ~~~" << std::endl;
    Box obj;
    LittlePony p("UNICORN!");
    Teddy b("BEAR");
    std::cout << obj << std::endl;
    std::cout << p;
    std::cout << b;
    std::cout << std::endl << std::endl;
}

void ajobforanelf()
{
    std::cout << "~~~~ A job for an Elf ~~~" << std::endl;
    IElf *lf = new PapaXmasElf;
    int giftcount = 0;
    while (lf->wrap()) {
        giftcount++;
    }
    delete lf;
    std::cout << "PapaXmasElf DONE " << std::to_string(giftcount) << " with PapaXmasTable and PapaXmasConveyorBelt" << std::endl;
}

void heresthebox()
{
    std::cout << "~~~~ Here's the box ~~~" << std::endl;
    IElf *lf = new PapaXmasElf;
    lf->setTable(new TableRand);
    lf->setConveyor(new ConveyorBeltRand);
    int giftcount = 0;
    while (lf->wrap()) {
        giftcount++;
    }
    delete lf;
    std::cout << "PapaXmasElf DONE " << std::to_string(giftcount) << " with TableRand and ConveyorBeltRand" << std::endl;
}

void warpmachine()
{
    std::cout << "~~~~ The Warp Machine, or one more step towards dementia ~~~" << std::endl;
    {
        IElf *lf = new PapaXmasElf;
        lf->setTable(new TableRand);
        lf->setConveyor(new MagicalCarpet);
        std::cout << "MAGICAL DONE" << std::endl;
        while (lf->wrap()) {
            std::cout << "+1 gift wrapped !!" << std::endl;
        }
        delete lf;
    }
    exit(0);
}

int main(int ac, char **av)
{
    srandom(time(NULL));
    mine_little_pony();
    ajobforanelf();
    heresthebox();
    if (ac > 1 && std::string(av[1]) == "-mc")
        warpmachine();
    return 0;
}
