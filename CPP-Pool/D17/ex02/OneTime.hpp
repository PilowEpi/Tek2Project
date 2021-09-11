/*
** EPITECH PROJECT, 2020
** CPOOL D17
** File description:
** CPOOL D17
*/

#ifndef ONE_TIME_HPP_
#define ONE_TIME_HPP_

#include "IEncryptionMethod.hpp"
#include <string>

class OneTime : public IEncryptionMethod
{
    public:
        OneTime(const std::string &key) : _key(key), _index(0) {};
        ~OneTime() {};
        void encryptChar(char plainchar);
        void decryptChar(char cipherchar);
        void reset() {_index = 0;};
    private:
        int _index;
        std::string _key;
};

#endif