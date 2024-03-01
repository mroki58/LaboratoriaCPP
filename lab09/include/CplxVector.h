#pragma once
#include "CplxNumber.h"

class CplxVector{
public:
    // Konstruktor domyslny
    CplxVector() = default;
    
    // Ustawia wspolrzedna X wektora na number, moze byc wykorzystane w chain call
    CplxVector & SetX(const CplxNumber & number);

    // Ustawia wspolrzedna Y wektora na CplxNumber(re,im)
    // moze byc wykorzystane w chain call
    CplxVector & SetY(double re, double im);
    
    //Ustawia wspolrzedna Y wektora na CplxNumber(re,im)
    // moze byc wykorzystane w chain call
    CplxVector & SetZ(double re, double im);

    //Wypisuje w zadanym formacie, wykorzystuje
    //Funkcje konwertujaca CplxNumber do std::string
    void Print() const;

    //Konstruktor konwertujacy w zadany sposob
    CplxVector(double x);

    //Funkcja zwracajaca referencje do pierwszej wspolrzednej
    const CplxNumber & X() const;

private:
    std::array<CplxNumber,3> _cords;
};