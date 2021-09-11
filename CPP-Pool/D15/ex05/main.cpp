#include "ex05.hpp"

#include <iostream>

int  float_to_int(float  const& f)
{
    return  static_cast <int >(f);
}

int main()
{
    array <int > a(4);

    a[3] = 1;

    const  auto b = a;
    b.dump();

    array <float > c;
    c.dump();
    c[2] = 1.1;
    c.dump();
    a = c.convertTo <int >(& float_to_int);
    a.dump();

    array <bool> x (3);
    x[3] = true;
    x.dump();
}