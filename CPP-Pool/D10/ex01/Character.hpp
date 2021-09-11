#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include "AWeapon.hpp"
#include "AEnemy.hpp"

class Character
{
    public:
        Character(const std::string &name);
        ~Character();

        void recoverAP();
        void equip(AWeapon *weapon);
        void attack(AEnemy *enemy);
        std::string const &getName() const;

        int getAP() const;
        AWeapon const *getWeapon() const;
    private:
        std::string _name;
        int _ap;
        AWeapon *_weapon;
};

std::ostream &operator<<(std::ostream &out, const Character &character);


#endif