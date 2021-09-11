#ifndef DROIDMEMORY_HPP_
#define DROIDMEMORY_HPP_

#include <iostream>
#include <string>

class DroidMemory
{
    public:
        DroidMemory();
        DroidMemory(const DroidMemory &other);
        // MF
        void setExp(size_t exp);
        void setFingerPrint(size_t fingerprint);

        size_t getExp() const;
        size_t getFingerPrint() const;


        // DroidMemory
        bool operator==(const DroidMemory &other) const;
        bool operator!=(const DroidMemory &other) const;

        bool operator<(const DroidMemory &other) const;
        bool operator>(const DroidMemory &other) const;
        bool operator<=(const DroidMemory &other) const;
        bool operator>=(const DroidMemory &other) const;

        // Size_t
        bool operator==(const size_t exp) const;
        bool operator!=(const size_t exp) const;

        bool operator<(const size_t exp) const;
        bool operator>(const size_t exp) const;
        bool operator<=(const size_t exp) const;
        bool operator>=(const size_t exp) const;

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