#include <iostream>

#include "Lemon.hpp"
#include "Banana.hpp"
#include "Lime.hpp"
#include "LittleHand.hpp"

#include "FruitBox.hpp"

int  main()
{
    Lemon l1;
    Lemon l2;
    Lemon l3;

    Banana b1;
    Banana b2;

    Lime i1;
    Lime i2;
    Lime i3;
    Lime i4;

    FruitBox box(9);

    box.putFruit(&l1);
    box.putFruit(&l2);
    box.putFruit(&l3);

    box.putFruit(&b1);
    box.putFruit(&b2);

    box.putFruit(&i1);
    box.putFruit(&i2);
    box.putFruit(&i3);
    box.putFruit(&i4);

    FruitBox lem(3);
    FruitBox ban(2);
    FruitBox lim(4);

    LittleHand::sortFruitBox(box, lem, ban, lim);

    std::cout << "box size (ex 0) :" << box.nbFruits() << std::endl;
    std::cout << "lem size (ex 3) :" << lem.nbFruits() << std::endl;
    std::cout << "ban size (ex 2) :" << ban.nbFruits() << std::endl;
    std::cout << "bim size (ex 4) :" << lim.nbFruits() << std::endl;

    FruitBox box2(9);

    box2.putFruit(&l1);
    box2.putFruit(&l2);
    box2.putFruit(&l3);

    box2.putFruit(&b1);
    box2.putFruit(&b2);

    box2.putFruit(&i1);
    box2.putFruit(&i2);
    box2.putFruit(&i3);
    box2.putFruit(&i4);

    FruitBox lem2(2);
    FruitBox ban2(3);
    FruitBox lim2(4);

    LittleHand::sortFruitBox(box2, lem2, ban2, lim2);

    std::cout << "box size (ex 1) :" << box2.nbFruits() << std::endl;
    std::cout << "lem size (ex 2) :" << lem2.nbFruits() << std::endl;
    std::cout << "ban size (ex 2) :" << ban2.nbFruits() << std::endl;
    std::cout << "bim size (ex 4) :" << lim2.nbFruits() << std::endl;

    return  0;
}