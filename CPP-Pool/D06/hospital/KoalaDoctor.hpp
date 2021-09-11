#ifndef KOALA_DOCTOR_HPP_
#define KOALA_DOCTOR_HPP_

#include <string>

#include "SickKoala.hpp"
#include "KoalaNurse.hpp"

class KoalaDoctor
{
    public:
        //Ctor
        KoalaDoctor(std::string name);

        //Dtor
        ~KoalaDoctor();

        // Members Functions
        void diagnose(SickKoala *koala);
        void timeCheck();
        std::string getName();
        int getID();

        // Properties
        std::string _name;
        bool _isWorking;
};

#endif