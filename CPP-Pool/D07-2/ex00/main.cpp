/*
** EPITECH PROJECT, 2020
** CPOOL7
** File description:
** CPOOL7
*/

#include <iostream>
#include <fstream>
#include <string>
#include "Skat.hpp"

int main (void)
{
    Skat s("Junior", 15);

    std::cout << "Soldier " << s.name() << std::endl;
    s.status();
    s.useStimPaks();

    {
        Skat s("Junior");
        Skat s2("Major");
        Skat s3("MEDIIIIIIIICC", 50);
        Skat s4("Poor", 1);
        Skat s5("Dick");
        Skat s6("Mutant", 5);
        Skat pp;
        Skat pp2;
        Skat pp3;
        Skat pp4;

        s.useStimPaks();
        s2.useStimPaks();
        s3.useStimPaks();
        s4.useStimPaks();
        s5.useStimPaks();
        s6.useStimPaks();
        s.useStimPaks();
        s2.useStimPaks();
        s3.useStimPaks();
        s4.useStimPaks();
        s5.useStimPaks();
        s6.useStimPaks();
        pp.useStimPaks();

        s.status();
        s2.status();
        s3.status();
        s4.status();
        s5.status();
        s6.status();
        pp.status();
        pp2.status();
        pp3.status();
        pp4.status();

        s.shareStimPaks(10, s2.stimPaks());
        s.status();
        s2.status();
        s3.addStimPaks(1000);
        s.status();

        s.status();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
        s.useStimPaks();
    }

    return 0;
}