#include "Ratatouille.hpp"

Ratatouille::Ratatouille()
{
}

Ratatouille::~Ratatouille()
{
}

Ratatouille::Ratatouille(Ratatouille const &other)
{
    this->s << other.s.str();
}

Ratatouille &Ratatouille::operator=(const Ratatouille &other)
{
    this->s.clear();
    this->s.str("");
    this->s << other.s.str();
    return *this;
}

Ratatouille &Ratatouille::addVegetable(unsigned char c)
{
    this->s << c;
    return *this;
}

Ratatouille &Ratatouille::addCondiment(unsigned int i)
{
    this->s << i;
    return *this;
}

Ratatouille &Ratatouille::addSpice(double d)
{
    this->s << d;
    return *this;
}

Ratatouille &Ratatouille::addSauce(const std::string &sauce)
{
    this->s << sauce;
}

std::string Ratatouille::kooc()
{
    return (this->s.str());
}