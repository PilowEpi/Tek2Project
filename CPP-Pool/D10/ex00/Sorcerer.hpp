#ifndef SORCERER_HPP_
#define SORCERER_HPP_

#include <string>
#include "Victim.hpp"

class Sorcerer
{
    public:
        explicit Sorcerer(std::string name, std::string _title);
        ~Sorcerer();

        std::string getName() const;
        std::string getTitle() const;

        void polymorph(const Victim &victim) const;
    protected:
    private:
        std::string _name;
        std::string _title;
};

std::ostream &operator<<(std::ostream &out, const Sorcerer &sorcerer);


#endif