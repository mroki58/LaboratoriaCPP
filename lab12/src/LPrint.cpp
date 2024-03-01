#include "LPrint.h"

void LPrint::operator()(const Line & fa) const
{
    std::cout << "y = " << fa._a << "* x + " << fa._b;
    std::cout << "\tx0 = " << fa.X0() <<  std::endl;
}

void LPrint::operator()(const LArray & arr) const
{
    for(int i=0; i<arr._numberOfEls; i++){
        std::cout << "y = " << arr[i]._a << "* x + " << arr[i]._b;
        std::cout << "\tx0 = " << arr[i].X0();
        if(i<arr._numberOfEls-1)
            std::cout <<"\n";
    }
}
