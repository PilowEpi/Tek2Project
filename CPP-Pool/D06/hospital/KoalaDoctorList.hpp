#ifndef KOALA_DOCTOR_LIST_HPP_
#define KOALA_DOCTOR_LIST_HPP_

#include <string>

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"

class KoalaDoctorList
{
    public:
        // Ctor
        KoalaDoctorList(KoalaDoctor *koala);

        // Dtor
        ~KoalaDoctorList();

        // Members Function
        bool isEnd();
        void append(KoalaDoctorList *node);
        KoalaDoctorList *getFromName(std::string name);
        KoalaDoctorList *remove(KoalaDoctorList *node);
        KoalaDoctorList *removeFromName(std::string name);
        void dump();

        // properties
        KoalaDoctor *_doctor;
        KoalaDoctorList *_next;
};

#endif