/*
** EPITECH PROJECT, 2020
** CPOOL D08
** File description:
** CPOOL D08
*/

#include <iostream>
#include <string>
#include "Droid.hpp"
#include "DroidMemory.hpp"

int main (void)
{
    Droid d ("rudolf") ;
    Droid d2 ("gaston") ;
    size_t DuraSell = 40;

    d << DuraSell ;
    d.setStatus (new std::string ("having some reset"));
    d2.setStatus (new std::string ("having some reset"));
    if ( d2 != d && !( d == d2 ) )
        std :: cout << "a droid is a droid , all its matter is what it 's doing " << std ::endl ;
    d(new std::string ("take a coffee"), 20);
    std::cout << d << std::endl ;
    while ( d(new std :: string ("Patrol around"), 20)) {
        if (! d(new std :: string ("Shoot some ennemies"), 50))
            d(new std :: string ("Run Away ") , 20) ;
        std :: cout << d << std :: endl ;
    }
    std :: cout << d << std :: endl ;

}