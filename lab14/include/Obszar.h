#pragma once 
#include <iostream>


class Obszar{
public:
    virtual void wyswietlInformacje() const = 0 ;

};


class Kontynent: public Obszar{
public:
    inline void wyswietlInformacje() const override
    {
        std::cout << "Kontynent!\n";
    }
};

class Kraj: public Obszar{
public:
    
    inline void wyswietlInformacje() const override
    {
        std::cout << "Kraj\n";
    }
};