#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <string>

class Arms
{
    public:
        // Ctor
        Arms(std::string serial = "A-01", bool functional = true);
        // Dtor
        // MF
        bool isFunctional() const;
        std::string serial();
        void informations() const;
        // Propreties
    private:
        bool _isFunctional;
        std::string _serial;
};

class Legs
{
    public:
        // Ctor
        Legs(std::string serial = "L-01", bool functional = true);
        // Dtor
        // MF
        bool isFunctional() const;
        std::string serial();
        void informations() const;
        // Propreties
    private:
        bool _isFunctional;
        std::string _serial;
};

class Head
{
    public:
        // Ctor
        Head(std::string serial = "H-01", bool functional = true);
        // Dtor
        // MF
        bool isFunctional() const;
        std::string serial();
        void informations() const;
        // Propreties
    private:
        bool _isFunctional;
        std::string _serial;
};

#endif