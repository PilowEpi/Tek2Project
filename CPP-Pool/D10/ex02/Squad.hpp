#ifndef SQUAD_HPP_
#define SQUAD_HPP_

#include <deque>
#include "ISquad.hpp"

class Squad : public ISquad
{
    public:
        Squad() {};
        Squad(const Squad &other);
        ~Squad();

        Squad &operator=(const Squad &other);

        int getCount() const final;
        ISpaceMarine* getUnit(int) final;
        int push(ISpaceMarine*) final;

    private:
        std::deque<ISpaceMarine *> _units;
};

#endif
