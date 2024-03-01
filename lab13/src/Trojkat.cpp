#include "Trojkat.h"

void Trojkat::wypisz(std::ostream & out) const
{
    out << "Trojkat bokach: " << _a << " " << _b << " " << _c << std::endl;
}

double Trojkat::polePow() const
{
    double x = (_a+_b+_c)/2;
    return sqrt(x*(x-_a)*(x-_b)*(x-_c));
}