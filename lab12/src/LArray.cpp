#include "LArray.h"

LArray::LArray(int numberOfEls)
{
    _array = new Line[3];
    _numberOfEls = numberOfEls;
}

LArray & LArray::Add(Line line)
{
    
    if(_iter < _numberOfEls){
    _array[_iter] = line;
    ++_iter;
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
