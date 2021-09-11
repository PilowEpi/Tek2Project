#include "Character.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include "Priest.hpp"
#include "Paladin.hpp"

int main (void)
{
    Priest Iopi("Iopi", 42);
    Mage Sully("Sully", 42);

    Iopi.CloseAttack();
    Sully.CloseAttack();
    Sully.RangeAttack();
    Iopi.TakeDamage(90);
    Iopi.Heal();
    std::cout << "Iopi has " << Iopi.getPv() << std::endl;
    std::cout << Sully.getPower() << std::endl;
    Sully.RestorePower();
    std::cout << Sully.getPower() << std::endl;
    Iopi.RangeAttack();
    std::cout << Iopi.getPower() << std::endl;
    Iopi.RestorePower();
    std::cout << Iopi.getPower() << std::endl;
    
}