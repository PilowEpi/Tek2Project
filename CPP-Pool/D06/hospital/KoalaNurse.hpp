#ifndef KOALA_NURSE_HPP_
#define KOALA_NURSE_HPP_

#include "SickKoala.hpp"

#include <string>

class KoalaNurse
{
    public:
        // Ctor
        KoalaNurse(int id);
        
        // Dtor
        ~KoalaNurse();

        // Members Functions
        void giveDrug(std::string, SickKoala *koala);
        std::string readReport(std::string filename);
        void timeCheck(void);
        int getID(void);

        // Properties
        int _id;
        bool _isWorking;

};

#endif