
#include "Errors.hpp"
#include "AtmosphereRegulator.hpp"

AtmosphereRegulator::AtmosphereRegulator()
try : BaseComponent() {
    throw NasaError("Not implemented.", "AtmosphereRegulator");
} 
catch (const std::exception& e) {
    
};

AtmosphereRegulator::~AtmosphereRegulator()
{
}
