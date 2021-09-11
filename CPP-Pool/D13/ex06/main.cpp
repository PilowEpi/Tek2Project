#include <iostream>

#include "Toy.hpp"
#include "ToyStory.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main()
{
    Buzz b("buzzi", "../buzz.txt");
    Woody w("wood", "../woody.txt");

    ToyStory::tellMeAStory("superStory.txt", b, &Toy::speak_es , w, &Toy::speak);
    return (0);
}