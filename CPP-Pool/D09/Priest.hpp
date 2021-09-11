#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Character.hpp"
#include "Mage.hpp"

class Priest : public Mage
{
    public:
        // Ctor
        Priest(const std::string &name, int level);

        // Getter

        std::string getWeaponName() const;

        // Technique

        int CloseAttack();
        void Heal();

    private:
    protected:
};

#endif