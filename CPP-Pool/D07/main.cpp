/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include "Federation.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

#include <string>

int main (void)
{
    Federation :: Starfleet :: Ship UssKreog (289 , 132 , "Kreog", 6) ;
    Federation :: Starfleet :: Captain James ("James T. Kirk") ;
    WarpSystem :: QuantumReactor QR ;
    WarpSystem :: QuantumReactor QR2 ;
    WarpSystem :: Core core (& QR ) ;
    WarpSystem :: Core core2 (& QR2 ) ;
    UssKreog . setupCore (& core ) ;
    UssKreog . checkCore () ;
    UssKreog . promote (& James ) ;
    Borg :: Ship Cube ;
    Cube . setupCore (& core2 ) ;
    Cube . checkCore () ;
    return 0;

}