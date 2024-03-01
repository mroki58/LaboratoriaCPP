#pragma once
#include "Obszar.h"
#include <iostream>

class Zwierze{
public:
    virtual void wydajDzwiek() const = 0;
    virtual void wyswietlInformacje() const = 0;
    virtual ~Zwierze()  {}
   
};


class Ptak: public Zwierze{
public:   
    Ptak(const Kraj * kraj): _kraj(new Kraj(*kraj))
    {}

    inline void wydajDzwiek() const override
    {
        std::cout << "Ptak wydaje dzwiek!\n";
    }
    inline void wyswietlInformacje() const override
    {
        _kraj->wyswietlInformacje();
    }

    ~Ptak() override
    {
        delete _kraj;
    }

private:
    Kraj * _kraj;

};

class Ssak: public Zwierze{
public:
    inline void wydajDzwiek() const override
    {
        std::cout << "Ssak wydaje dzwiek!\n";
    }
    inline void wyswietlInformacje() const override
    {}

};