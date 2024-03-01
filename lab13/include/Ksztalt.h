#pragma once
#include <iostream>
#include <cmath>

// Klasa abstrakcyjna
class Ksztalt{
public:
    // Metody wirtualne (Dzialanie funkcji override w Kolo.h i Trojkat.h)
    virtual void wypisz(std::ostream & out) const = 0;
    virtual double polePow() const = 0;
};

// Wypisuje czym jest ksztalt i jakiego sa jego wlasciwosci 
void wypisz(const Ksztalt & ksztalt);