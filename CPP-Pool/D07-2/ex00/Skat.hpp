#ifndef SKAT_HPP_
#define SKAT_HPP_

#include <string>

class Skat
{
    public:
        Skat(const std::string &name = "bob", int stimPaks = 15);
        ~Skat();

        unsigned int &stimPaks();
        const std::string &name();

        void shareStimPaks(unsigned int number, unsigned int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    private:
        std::string _name;
        unsigned int _stimPaks;
};

#endif