#include "Kolo.h"

void Kolo::wypisz(std::ostream & out) const
{
    out << "Kolo o promieniu: " << _r << std::endl;
}

double Kolo::polePow() const
{
    return PI * _r * _r;
}