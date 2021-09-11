#include "BF_Translator.hpp"

#include <err.h>

int main(int ac, char **av)
{
    if (ac != 3 && ac != 2)
        errx(1, "missing files");

    BF_Translator t;
    std::string def = "out.c"; 
    if (ac == 3)
        t.translate(av[1], av[2]);
    if (ac == 2)
        t.translate(av[1], def);
    return (0);
}
