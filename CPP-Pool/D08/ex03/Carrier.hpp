#ifndef CARRIER_HPP_
#define CARRIER_HPP_

#include <string>

#include "Droid.hpp"

class Carrier
{
    public:
        Carrier(std::string id = "");

        // MF

        //      setter

        void setSpeed(size_t speed);
        void setEnergy(size_t energy);
        void setNumberOfDroid(size_t numberOfDroid);

        //      getter

        size_t getSpeed() const;
        size_t getEnergy() const;
        Droid *const*getDroid() const;

        //      Speed

        size_t calculSpeed(size_t numberOfDroid) const;
        size_t getNumberOfDroid() const;

        void assignDroidToCarrier(size_t pos, Droid &droid);
    private:

        std::string _id;
        size_t _energy;
        const size_t _attack = 100;
        const size_t _toughness = 90;
        size_t _speed;
        size_t _numberOfDroid;
        Droid *_droids[5];
};

Carrier &operator<<(Carrier &carrier, Droid &droid);
Carrier &operator>>(Carrier &carrier, Droid &droid);

#endif