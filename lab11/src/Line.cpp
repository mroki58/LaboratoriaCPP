#include "Line.h"

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

/////////////////////////////////////////////////////////////////////////

LArray::LArray(int numberOfEls)
{
    _array = new Line[3];
    _numberOfEls = numberOfEls;
}

LArray & LArray::Add(Line line)
{
    
    static int i = 0;
    if(i < _numberOfEls){
    _array[i] = line;
    ++i;
    }else{
        std::cout << "Element nie zostal dodany do tablicy\n";
    }
    return *this;
}

Line & LArray::operator[](int i) const
{
    if(i < _numberOfEls && i>=0){
        return _array[i];
    }
    std::cout << "Blad dostepu\n";
    exit(0);

}


LArray::~LArray()
{
    delete [] _array;
}

/////////////////////////////////////////////////////////////////////

void LPrint::operator()(const Line & fa) const
{
    std::cout << "y = " << fa._a << "* x + " << fa._b;
    std::cout << "    x0 = " << fa.X0() <<  std::endl;
}

void LPrint::operator()(const LArray & arr) const
{
    for(int i=0; i<arr._numberOfEls; i++){
        std::cout << "[" << i << "] y = " << arr[i]._a << "* x + " << arr[i]._b;
        std::cout << "        x0 = " << arr[i].X0() <<  std::endl;
    }
}

