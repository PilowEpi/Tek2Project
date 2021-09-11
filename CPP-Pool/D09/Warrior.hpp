#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : virtual public Character
{
    public:
        // Ctor
        Warrior(const std::string &name, int level, const std::string &weaponName = "hammer");

        // Getter

        std::string getWeaponName() const;

        // Technique

        int CloseAttack();
        int RangeAttack();

    private:
    protected:
        std::string _weaponName;
};

#endif