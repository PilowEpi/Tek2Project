/*
** EPITECH PROJECT, 2020
** CPOOL D17
** File description:
** CPOOL D17
*/

#ifndef CESAR_HPP_
#define CESAR_HPP_

#include "IEncryptionMethod.hpp"

class Cesar : public IEncryptionMethod
{
    public:
        Cesar() : _shift(3) {};
        ~Cesar() {};
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset() {_shift = 3;};
    private:
        int _shift;
};

#endif