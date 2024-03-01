#pragma once
#include <stdio.h>

typedef float* ciag;
typedef float typCiagu;

extern ciag * tablica_wskaznikow;
extern int ilosc_ciagow;
typedef int rozmiarCiagu;
typedef float(*operacja)(ciag dane,rozmiarCiagu rozmiar);

// Funkcja zwraca wskaznik do zaalokowanej tablicy float 
// Elementy tablicy to wyrazy ciagu geometrycznego o a1=pierwszy oraz ilorazie podawanym jako argument
// Przyjmuje argumenty int rozmiar oraz float iloraz
ciag InicjalizujCiagGeometryczny(int,typCiagu pierwszy,float iloraz);

// Wypisuje zawartosc tablicy floatow o rozmiarze podanym przez uzytkownika
// Przyjmuje jako argumenty wskaznik na poczatek ciagu, oraz rozmiar tego ciagu
void Wypisz(ciag ,int );

// Dealokuje wszystkie zaalokowane tablice
void UsunCiagi();

