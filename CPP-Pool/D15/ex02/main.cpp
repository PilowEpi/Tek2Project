#include  <iostream>
#include  <string>

#include "ex02.hpp"

int  main()
{
    float  tab [3] = {3, 0.2f, 2.2f};
    float  minimum = templateMin(tab , 3);
    std::cout  << "templateMin(tab , 2) = " << minimum  << std::endl;
    //minimum = nonTemplateMin(tab , 2);
    //std::cout  << "nonTemplateMin(tab , 2) = " << minimum  << std::endl;
    return 0;
}