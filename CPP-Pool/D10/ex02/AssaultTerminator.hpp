#ifndef ASSAULT_TERMINATOR_HPP_
#define ASSAULT_TERMINATOR_HPP_

#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
    public:
        AssaultTerminator();
        ~AssaultTerminator();

        ISpaceMarine *clone() const final;
        void battleCry() const final;
        void rangedAttack() const final;
        void meleeAttack() const final;
    private:
};

#endif