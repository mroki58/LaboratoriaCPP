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

Angle Angle::fromDegrees(double value)
{
    Angle temp(value,DEGREE);
    return temp;
}

Angle Angle::fromRadians(double value)
{
    Angle temp(value,RADIAN);
    return temp;
}

double Angle::toRad() const
{
    return _angle;
}   
double Angle::toDeg() const
{
    return (_angle * 360)/(2*M_PI); 
}

Angle & Angle::add(const Angle & phi2)
{
    _angle += phi2.toRad();
    if(_angle>2*M_PI)
    {
        _angle = _angle - 2*M_PI;
    }
    return *this;
}

void Angle::print() const
{
    std::cout <<"Angle [rad]: "<<_angle<<std::endl;
}

Angle Angle::distance(const Angle & phi1,const Angle & phi2) 
{
    Angle temp(fabs(phi1._angle - phi2._angle),RADIAN);
    return temp;
}