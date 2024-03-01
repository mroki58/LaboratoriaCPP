#pragma once
#include <iostream>

class Line{
public:
    friend class LPrint;
    friend class LArray;
   
    Line(double a = 1, double b = 1);

    Line(int a);

    double operator()(double x) const;

    double X0() const;

private:
    double _a;
    double _b;

};