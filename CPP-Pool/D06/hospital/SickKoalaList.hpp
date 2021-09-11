#ifndef SICK_KOALA_LIST_HPP_
#define SICK_KOALA_LIST_HPP_

#include "SickKoala.hpp"

class SickKoalaList
{
    public:
        // Ctor
        SickKoalaList(SickKoala *koala);

        // Dtor
        ~SickKoalaList();

        // Members Function
        bool isEnd();
        void append(SickKoalaList *node);
        SickKoalaList *getFromName(std::string name);
        SickKoalaList *remove(SickKoalaList *node);
        SickKoalaList *removeFromName(std::string name);
        SickKoala *getContent();
        SickKoalaList *getNext();
        void dump();

        // properties
        SickKoala *_koala;
        SickKoalaList *_next;
};

#endif