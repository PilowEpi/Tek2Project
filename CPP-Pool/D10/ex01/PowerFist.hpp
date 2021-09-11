#ifndef POWER_FIST_HPP_
#define POWER_FIST_HPP_

#include "AWeapon.hpp"

class PowerFist : public AWeapon
{
    public:
        PowerFist();

        void attack() const;

    private:
};

#endif