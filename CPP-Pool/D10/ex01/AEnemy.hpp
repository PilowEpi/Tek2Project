#ifndef AENEMY_HPP_
#define AENEMY_HPP_

#include <string>

class AEnemy
{
    public:
        // Ctor Dtor
        AEnemy(int hp, const std::string &type);
        virtual ~AEnemy();

        // MF
        virtual void takeDamage(int damage);
        std::string const &getType() const;
        int getHP() const;

    private:
        std::string _type;
        int _hp;
};

#endif