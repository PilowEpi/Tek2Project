#include "ex03.hpp"

#include <iostream>

template<typename T>
void print(const T &elem)
{
    std::cout << elem << std::endl;
}

int main(void)
{
    int  tab[] = { 11, 3, 89, 42 };

    foreach(tab , print <int >, 4);
    std::string tab2[] = { "j'", "aime", "les", "templates", "!" };
    foreach(tab2 , print , 5);
    return  0;
}