#include "Angle.h"

Angle::Angle(double value, Angle_Type type)
{
    _angleType = type;

    switch(_angleType)
    {
        case DEGREE:
        std::cout << "... creating angle from degrees." << std::endl;
        value *= (2*M_PI)/360;
        break;

        case RADIAN:
        std::cout <<"... creating angle from radians." << std::endl;
        break;
    }
    

    while(value>2*M_PI) value -= 2*M_PI;
    while(value<0)      value += 2*M_PI;

    _angle = value;
}

double Angle::toRad() const
{
    return _angle;
}   
double Angle::toDeg() const
{
    return (_angle * 360)/(2*M_PI); 
}

void Angle::add(const Angle & phi2)
{
    _angle += phi2.toRad();
}