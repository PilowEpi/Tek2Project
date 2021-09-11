
#include "Toy.hpp"
#include "Buzz.hpp"
#include "Woody.hpp"

int main (void)
{
    Woody w("Wood", "../woody.txt");
    Woody w2();
    Buzz bu("the eclair", "../buzz.txt");

    if (bu.getType() == Toy::BUZZ) {
        std::cout  << "buzz is: " << bu.getName() << std::endl;
        std::cout << bu.getAscii() << std::endl;
    }

    if (w.getType() == Toy::WOODY) {
        std::cout  << "woody is: " << w.getName() << std::endl;
        std::cout << w.getAscii() << std::endl;
    }
}