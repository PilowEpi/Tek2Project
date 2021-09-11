#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin: virtual public Warrior, virtual public Priest
{
    public:
        Paladin(const std::string &name, int level, const std::string &weaponName = "hammer");

        int CloseAttack();
        int RangeAttack();
        void Heal();
        void RestorePower();
        int Intercept();
    protected:
    private:
};

#endif