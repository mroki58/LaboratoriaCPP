#pragma once
#include <iostream>
#include <cstdlib>

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
//////////////////////////////////////////////////////

class LArray{
public:
    friend class LPrint;
    LArray(int numberOfEls);

    LArray & Add(Line line);

    Line & operator[](int i) const;

    ~LArray();
private:
    Line * _array;
    int _numberOfEls;

};
/////////////////////////////////////////////////////

class LPrint
{
public:
        LPrint() = default;
        void operator ()(const Line & fa) const;
        void operator ()(const LArray & arr) const;
};


