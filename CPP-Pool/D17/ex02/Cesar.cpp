#include "Cesar.hpp"
#include <iostream>
#include <cctype>

void Cesar::encryptChar(char plainchar)
{
    if (plainchar >= 'a' && plainchar <= 'z') {
        plainchar += _shift;
        while (plainchar < 'a' || plainchar > 'z')
            plainchar -= 26;
    } else if (plainchar >= 'A' && plainchar <= 'Z') {
        plainchar += _shift;
        while (plainchar < 'A' || plainchar > 'Z')
            plainchar -= 26;
    }
    std::cout << plainchar;
    _shift++;
}

void Cesar::decryptChar(char cipherchar)
{
    if (cipherchar >= 'a' && cipherchar <= 'z') {
        cipherchar -= _shift;
        while (cipherchar < 'a' || cipherchar > 'z')
            cipherchar += 26;
    } else if (cipherchar >= 'A' && cipherchar <= 'Z') {
        cipherchar -= _shift;
        while (cipherchar < 'A' || cipherchar > 'Z')
            cipherchar += 26;
    }
    std::cout << cipherchar;
    _shift++;
}