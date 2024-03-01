#pragma once 
#include "Lin.h"

class LArray{
public:
    friend class LPrint;
    
    LArray(int numberOfEls);

    LArray & Add(Line line);

    Line & operator[](int i) const;

    ~LArray();

    Line * _array;
    int _numberOfEls;
    int _iter = 0;

};