#ifndef PLASMA_RIFLE_HPP_
#define PLASMA_RIFLE_HPP_

#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
    public:
        PlasmaRifle();

        void attack() const;

    private:
};

#endif