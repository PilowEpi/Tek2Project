#ifndef TACTICAL_MARINE_HPP_
#define TACTICAL_MARINE_HPP_

#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
    public:
        TacticalMarine();
        ~TacticalMarine();

        ISpaceMarine *clone() const final;
        void battleCry() const final;
        void rangedAttack() const final;
        void meleeAttack() const final;
    private:
        
};

#endif