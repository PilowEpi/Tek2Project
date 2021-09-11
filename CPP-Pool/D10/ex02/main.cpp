#include "ISquad.hpp"
#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>
#include <memory>

int main ()
{
    std::unique_ptr<ISquad> vlc(new Squad);
    vlc->push(new TacticalMarine);
    vlc->push(new AssaultTerminator);
    for (int i = 0; i < vlc -> getCount () ; ++ i ) {
        const auto cur = vlc -> getUnit ( i ) ;
        cur -> battleCry () ;
        cur -> rangedAttack () ;
        cur -> meleeAttack () ;
    }
    return 0;
}