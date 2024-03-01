#include "CplxNumber.h"

CplxNumber::CplxNumber(double re, double im): _re(re), _im(im) {}

void CplxNumber::Print() const
{
    std::cout << "(" << _re << ", " << _im <<")\n";
}

CplxNumber::operator std::string() const
{
    std::string temp = "(";
    temp += std::to_string(_re);
    temp += ",";
    temp += std::to_string(_im);
    temp += ")";
    return temp;

}

double CplxNumber::Abs(const CplxNumber & number)
{
    return sqrt(number._re * number._re + number._im * number._im);   
}

CplxNumber::operator double() const
{
    return CplxNumber::Abs(*this);   
}











