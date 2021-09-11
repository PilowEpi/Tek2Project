#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character
{
    public:
        // Ctor
        Mage(const std::string &name, int level);

        // Getter

        std::string getWeaponName() const;

        // Technique

        int CloseAttack();
        void RestorePower();
        int RangeAttack();

    private:
    protected:
};

#endif