#include <iostream>

#include "Lemon.hpp"
#include "Banana.hpp"

#include "FruitBox.hpp"

int  main()
{
    Lemon l;
    Banana b;

    std::cout  << l.getVitamins () << std::endl;
    std::cout  << b.getVitamins () << std::endl;

    std::cout  << l.getName () << std::endl;
    std::cout  << b.getName () << std::endl;

    Fruit& f = l;

    std::cout  << f.getVitamins () << std::endl;
    std::cout  << f.getName () << std::endl;

    FruitBox box(1);
    std::cout << "put1 (ex 1): " << box.putFruit(&b) << std::endl;
    std::cout << "put2 (ex 0): " << box.putFruit(&l) << std::endl;

    FruitBox box2(3);
    std::cout << "put1 (ex 1): " << box2.putFruit(&b) << std::endl;
    std::cout << "put2 (ex 0): " << box2.putFruit(&b) << std::endl;

    std::cout << "size (ex 1): " << box2.nbFruits() << std::endl;

    std::cout << "put3 (ex 1): " << box2.putFruit(&l) << std::endl;
    std::cout << "size (ex 2): " << box2.nbFruits() << std::endl;

    Fruit *f2 = box2.pickFruit();

    std::cout << "pickFruit vit (ex 5/banana): " << f2->getVitamins();
    std::cout << " " << f2->getName() << std::endl;

    return  0;
}