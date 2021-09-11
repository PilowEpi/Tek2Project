#ifndef VICTIM_HPP_
#define VICTIM_HPP_

#include <string>

class Victim
{
    public:
        explicit Victim(std::string name);
        ~Victim();

        std::string getName() const;

        virtual void getPolymorphed() const;
    private:
        std::string _name;
};

std::ostream &operator<<(std::ostream &out, const Victim &victim);

#endif