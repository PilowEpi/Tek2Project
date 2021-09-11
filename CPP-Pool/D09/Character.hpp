#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <string>
#include <iostream>

class Character
{
    public:
        //Ctor
        Character(const std::string &name, int level);

        // Dtor
        ~Character();

        // Getter
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;

        // Setter

        void setPv(int pv);
        void setPower(int power);

        // Technique

        int CloseAttack();
        void Heal();
        int RangeAttack();
        void RestorePower();

        // Other

        void TakeDamage(int damage);

        enum AttackRange {
            CLOSE,
            RANGE
        };
        AttackRange Range;
    protected:
        

        std::string _name;
        
        int _level;
        int _pv;
        int _power;

        // Characteristics
        int _strength;
        int _stamina;
        int _intelligence;
        int _spirit;
        int _agility;
    
};

#endif