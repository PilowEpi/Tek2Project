#ifndef AWEAPON_HPP_
#define AWEAPON_HPP_

#include <string>

class AWeapon
{
    public:
        // Ctor Dtor
        AWeapon(const std::string& name, int apcost, int damage);
        virtual ~AWeapon();

        // MF
        std::string const &getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
    private:
        std::string _name;
        int _damage;
        int _action_points;
};

#endif