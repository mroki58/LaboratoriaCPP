#include "Lin.h"

Line::Line(double a, double b): _a(a) , _b(b) {}

Line::Line(int a): Line(a,a) {}

double Line::operator()(double x) const
{
    return 1+x;
}

double Line::X0() const
{
    if(_a != 0)
        return -(_b/_a);
    return 0;
}
