#ifndef DROID_HPP_
#define DROID_HPP_

#include <string>

#include "DroidMemory.hpp"

class Droid
{
    public:
        explicit Droid(std::string serial);
        Droid(const Droid &other);

        ~Droid();
    
        // MF
        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string getStatus() const;

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

        Droid &operator=(const Droid &other);
        bool operator==(const Droid &other) const;
        bool operator!=(const Droid &other) const;

        void setBattleData(DroidMemory *battleData);
        DroidMemory *getBattleData() const;

    private:
        std::string _id;
        size_t _energy;
        const size_t _attack = 25;
        const size_t _toughness = 15;
        std::string *_status;
        DroidMemory *_battleData;
};

std::ostream &operator<<(std::ostream &out, const Droid &droid);
Droid &operator<<(Droid &other, size_t &energy);

#endif