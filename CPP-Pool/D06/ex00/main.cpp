/*
** EPITECH PROJECT, 2020
** CPOOL D06
** File description:
** CPOOL D06
*/

#include <iostream>
#include <fstream>

int cat(int argc, char *argv[])
{
    std::fstream file;
    std::string s;

    for (int i = 1; i < argc; i++) {
        file.open(argv[i], std::ios::in);
        if (!file) {
            std::cerr << "my_cat: "<< argv[i] <<": No such file or directory" << std::endl;
        } else {
            while (getline(file, s))
                std::cout << s << std::endl;
            file.close();
        }
    }
    return (0);
}

int main (int argc, char *argv[])
{
    if (argc == 1) {
        std::cerr << "my_cat: Usage: " << argv[0] << " file [...]" << std::endl;
        return (84);
    }
    
    return (cat(argc, argv));
}