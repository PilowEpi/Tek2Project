#ifndef KOALA_NURSE_LIST_HPP_
#define KOALA_NURSE_LIST_HPP_

#include "KoalaNurse.hpp"

class KoalaNurseList
{
    public:
        // Ctor
        KoalaNurseList(KoalaNurse *nurse);

        // Dtor
        ~KoalaNurseList();

        // Members Function
        bool isEnd();
        void append(KoalaNurseList *node);
        KoalaNurseList *getFromID(int id);
        KoalaNurseList *remove(KoalaNurseList *node);
        KoalaNurseList *removeFromID(int id);
        void dump();

        // properties
        KoalaNurse *_nurse;
        KoalaNurseList *_next;
};

#endif