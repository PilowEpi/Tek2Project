#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <string>

class DroidMemory
{
    public:
        DroidMemory();

        // MF
        void setExp(size_t exp);
        void setFingerPrint(size_t fingerprint);

        size_t getExp() const;
        size_t getFingerPrint() const;


    private:
        size_t _fingerPrint;
        size_t _exp;
};

DroidMemory &operator>>(DroidMemory &mem1, DroidMemory &mem2);
DroidMemory &operator<<(DroidMemory &mem1, const DroidMemory &mem2);

DroidMemory &operator+=(DroidMemory &mem1, const size_t exp);
DroidMemory &operator+=(DroidMemory &mem1, const DroidMemory &mem2);

std::ostream &operator<<(std::ostream &out, const DroidMemory &mem);

DroidMemory &operator+(DroidMemory &mem1, const size_t exp);
DroidMemory &operator+(DroidMemory &mem1, DroidMemory &mem2);

#endif