#include <exception>
#include <stdexcept>
#include "BaseComponent.hpp"
#include "AtmosphereRegulator.hpp"

#include "SimplePtr.hpp"
int main ()
{
    try {
        SimplePtr regulator(new AtmosphereRegulator);
        SimplePtr regulator2(new AtmosphereRegulator);
        throw std::runtime_error("MDR");
    } catch (...) {}
    return 0;
}