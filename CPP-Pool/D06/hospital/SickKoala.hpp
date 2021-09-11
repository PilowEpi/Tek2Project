#ifndef SICK_KOALA_HPP_
#define SICK_KOALA_HPP_

#include <string>

class SickKoala
{
    public:
        // Ctor
        SickKoala(std::string name);
        
        // Dtor
        ~SickKoala();
        
        // Members Functions
        void poke();
        bool takeDrug(std::string drugName);
        void overDrive(std::string question);

        // Properties
        std::string _name;
};

#endif