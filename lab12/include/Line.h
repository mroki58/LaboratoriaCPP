#pragma once
#include "Lin.h"
#include "LArray.h"
#include "LPrint.h"
#include <iostream>
#include <cstdlib>

class LArraySmartPtr{
public:
// inicjalizacja ptr jako zmyslnego wskaznika
LArraySmartPtr(LArray * ptr): _ptr(ptr), _refCount(nullptr)
{
    _refCount = new int(1);
}

// Operator przypisania
LArraySmartPtr & operator=(LArraySmartPtr & smartptr);

//Przeladowane operatory
LArray & operator*();

LArray * operator->();


~LArraySmartPtr();


private:
    LArray * _ptr;
    int * _refCount;

    // Funkcja wykorzystywan ado zwalniania pamieci
    void release();
    
};
/////////////////////////////////////////////////////

