#ifndef SUPER_MUTANT_HPP_
#define SUPER_MUTANT_HPP_

#include <string>
#include "AEnemy.hpp"

class SuperMutant : public AEnemy
{
    public:
        SuperMutant();
        ~SuperMutant() final;

        void takeDamage(int damage) override;
    private:
};

#endif