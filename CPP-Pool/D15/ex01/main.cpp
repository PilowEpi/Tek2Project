#include <iostream>

#include "ex01.hpp"

class toto
{
public :
    toto () = default ;
    toto & operator =( const toto &) = delete ;
    toto ( const toto &) = delete ;
    bool operator ==( const toto &) const { return true ; }
    bool operator >( const toto &) const { return false ; }
    bool operator <( const toto &) const { return false ; }
};

int main(void)
{
    toto a,  b;

    std::cout << "expect 0: " << compare(a, b) << std::endl;
    std::cout << "expect -1: " << compare(1, 2) << std::endl;

    std::cout << "expect 1: " << compare<const char *>("chaineZ", "chaineA42") << std::endl;
    const char *s1 = "42";
    const char *s2 = "lulz";
    std::cout << "expect -1: " << compare(s1, s2) << std::endl;
}