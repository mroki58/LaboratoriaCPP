#pragma once
#include <iostream>

class Car{
public:
    //Konstruktor(y) domyslny
    Car(const char * brand ="",int year = 0, int mileage = 0);

    //Konstruktor kopiujacy
    Car(const Car & car);

    //Konstruktor przenoszacy
    Car(Car && car);

    //Operator przypisania kopiujacy
    const Car & operator=(const Car & car);
    
    //Operator przypisania przenoszacy
    const Car & operator=(Car && car);

    //Destruktor
    ~Car();

    // Wypisuje w zadanym formacie
    void displayInfo() const;

private:
    // metoda wykorzystywana przez inne metody do dealokacji pamieci na _year
    void dtor();

    // metoda wykorzystywana przez move assignment i move constructor, bez alokacji pamieci
    void ctor(const Car & car);

    // metoda wykorzystywana przez cp assignment i cp constructor, alokuje pamiec
    void ctorcp(std::string brand, int year,int mileage);

    // wykorzystywana przez mv do zamiany wartosci pol obiektu
    void replace();

    std::string _brand;
    int * _year;
    int _mileage;

};