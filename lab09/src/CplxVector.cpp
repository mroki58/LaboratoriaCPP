#include "CplxVector.h"

CplxVector & CplxVector::SetX(const CplxNumber & number)
{
    _cords[0] = number;
    return *this;
}

CplxVector & CplxVector::SetY(double re, double im) 
{
    _cords[1] = CplxNumber(re, im);
    return *this;
}

CplxVector & CplxVector::SetZ(double re, double im) 
{
    _cords[2] = CplxNumber(re, im);
    return *this;
}

void CplxVector::Print() const
{
    std::cout << "[" << static_cast<std::string>(_cords[0]);
    for(int i=1;i<3;i++)
    {
        std::cout << ", " << static_cast<std::string>(_cords[i]);
    }
    std::cout << "]\n";
}

CplxVector::CplxVector(double x)
{
    _cords[0] = CplxNumber(x,x);
    _cords[1] = CplxNumber(x,x);
    _cords[2] = CplxNumber(x,x);
}

const CplxNumber & CplxVector::X() const
{
    return _cords[0];
}