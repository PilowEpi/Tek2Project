#include "Character.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "RadScorpion.hpp"
#include "AEnemy.hpp"
#include "AWeapon.hpp"
#include <iostream>

template <class AEnemy>
void testEnemy()
{

}

int main()
{

    const auto preda = new  Character("Predator");
    const auto prey = new  RadScorpion ();
    
    testEnemy<RadScorpion>();

    std::cout  << *preda;
    AWeapon *pr(new  PlasmaRifle ());
    AWeapon *pf(new  PowerFist ());

    preda ->equip(pr);
    std::cout  << *preda;preda ->equip(pf);

    preda ->attack(prey);
    std::cout  << *preda;

    preda ->equip(pr);
    std::cout  << *preda;

    preda ->attack(prey);
    std::cout  << *preda;

    preda ->attack(prey);
    std::cout  << *preda;

    return  0;

}