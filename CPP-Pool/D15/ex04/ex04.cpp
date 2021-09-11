#include "ex04.hpp"
#include <string>

template <class T>
bool Tester<T>::equal(const T &a, const T &b)
{
    if (a == b) return true;
    return false;
};

template class Tester<int>;
template class Tester<float>;
template class Tester<double>;
template class Tester<std::string>;