#pragma once
#include <iostream>
#include <cmath>
#include <array>

class CplxNumber{
public:   
    // Konstruktory inicjalizujace obiekt klasy CplxNumber
    CplxNumber(double re=0, double im=0);

    // Wypisuje w zadanym formacie obiekt CplxNumber
    void Print() const;

    // Funkcja konwertujaca CplxNumber na std::string
    operator std::string() const;

    // Zwrca modul z CplxNumber number
    static double Abs(const CplxNumber & number);

    // Funkcja konwertujaca jawnie CplxNUmber na modul z CplxNumber
    explicit operator double() const;


private:
    double _re;
    double _im;


};