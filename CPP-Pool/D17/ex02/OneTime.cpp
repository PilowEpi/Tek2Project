
#include "OneTime.hpp"
#include <cctype>
#include <string>
#include <algorithm>
#include <iostream>

int getEncrypt(int index, std::string key)
{
    std::string alpha = "abcdefghijklmnopqrstuvwxyz";
    std::string beta = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if (key[index] >= 'a' && key[index] <= 'z')
       for (int i = 0; i < alpha.size(); i++) {
           if (alpha[i] == key[index])
            return i;
       }
    if (key[index] >= 'A' && key[index] <= 'Z')
        for (int i = 0; i < beta.size(); i++) {
           if (beta[i] == key[index])
            return i;
       }
    return 0;
}

void OneTime::encryptChar(char plainchar)
{
    if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar += getEncrypt(_index, _key);
        if (plainchar < 'a' || plainchar > 'z')
            plainchar -= 26;
    } else if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar += getEncrypt(_index, _key);
        if (plainchar < 'A' || plainchar > 'Z')
            plainchar -= 26;
    }
    std::cout << plainchar;
    _index++;
    if (_index == _key.size())
        _index = 0;
}

void OneTime::decryptChar(char cipherchar)
{
    if (cipherchar >= 'a' && cipherchar <= 'z') {
        cipherchar -= getEncrypt(_index, _key);
        if (cipherchar < 'a' || cipherchar >= 'z')
            cipherchar += 26;
    } else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        cipherchar -= getEncrypt(_index, _key);
        if (cipherchar < 'A' || cipherchar >= 'Z')
            cipherchar += 26;
    }
    std::cout << cipherchar;
    _index++;
    if (_index == _key.size())
        _index = 0;
}