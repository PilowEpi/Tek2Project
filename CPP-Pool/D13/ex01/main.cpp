#include "Picture.hpp"
#include "Toy.hpp"


int main (void)
{
    Toy toto(Toy::BASIC_TOY, "toy", "../alien.txt");
    Toy titi(toto);

    std::cout << toto.getAscii() << std::endl;
    std::cout << titi.getAscii() << std::endl;
}