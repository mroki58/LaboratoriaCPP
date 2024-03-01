#pragma once
#include <iostream>
#include <cmath>

// Typ wyliczeniowy, ktory wykorzystujemy w konstruktorze klasy Angle
enum Angle_Type
{
    DEGREE,RADIAN
};

class Angle{
    public:
        //Wykorzystuje kontruktor do zainicjalizowania elementu wartoscia value zapisana w stopniach
        static Angle fromDegrees(double value);

        //Wykorzystuje kontruktor do zainicjalizowania elementu wartoscia value zapisana w radianach
        static Angle fromRadians(double value);

        // Zwraca wartosc pola obiektu _angle (w radianach)
        double toRad() const;

        // Zwraca wartosc pola obiektu _angle (w stopniach)
        double toDeg() const;

        // Do pola _angle obiektu dodaje pole _angle obiektu Phi2
        Angle & add(const Angle & Phi2);

        //Wypisuje w odpowiednim formacie wartosc _angle
        void print() const;

        // Zwraca element bedacy wartoscia bezwzgledna z phi1._angle i phi2._angle
        static Angle distance(const Angle & phi1,const Angle & phi2);

    private:
        // Konstruktor przypisujacy zmiennej obiektu - _angle wartosc z zakresu 0-2PI w radianach, na podstawie wartosci value i type
        // value to dowolna wartosc kat, ktory jest pozniej konwertowany do wartosci z zakresu 0-2PI
        // type mowi nam jak mamy traktowac wartosc value 
        // - jezeli type = RADIAN, traktujemy go jako kat podany w radianach
        // - type = DEGREE, w stopniach 
        Angle(double value, Angle_Type type);
        
        // Zmienna przechowuje kat w radianach od 0-2Pi
        double _angle;

        //Zmienna typu wyliczeniowego sluzy jako informacja wykorzystywana podczas przypisywania wartosci angle
        Angle_Type _angleType; 
};