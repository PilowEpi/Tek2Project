#include <vector>
#include <deque>
#include <list>
#include <iostream>

#include "find.hpp"

int main(void)
{
    std::vector<int> vect;

    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(3);
    vect.push_back(4);

    std::deque<int> dequ;

    dequ.push_back(1);
    dequ.push_back(2);
    dequ.push_back(3);
    dequ.push_back(4);

    std::list<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);

    std::cout << *do_find(vect, 3) << std::endl;
    std::cout << *do_find(dequ, 3) << std::endl;
    std::cout << *do_find(list, 3) << std::endl;

    return 0;
}