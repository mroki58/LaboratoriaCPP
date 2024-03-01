#pragma once
#include <iostream>
typedef float(*operacja)(ciag dane, rozmiarCiagu rozmiar);

// Zwraca wartosc float - sume wszystkich elementow tablicy
// Jako argument przyjmuje wskaznik do tablicy oraz jej rozmiar
float Suma(ciag geometryczny,int rozmiar);

// Zwraca wartosc float - srednia arytmetyczna wszystkich elementow tablicy
// Jako argument przyjmuje wskaznik do tablicy oraz jej rozmiar
float Srednia(ciag geometryczny, int rozmiar);

// Zwraca wartosc float - iloczyn wszystkich elementow tablicy
// Jako argument przyjmuje wskaznik do tablicy oraz jej rozmiar
//float Iloczyn(ciag geometryczny,int rozmiar);

// Zwraca wartosc float - najwieksza wartosc w tablicy
// Jako argument przyjmuje wskaznik do tablicy oraz jej rozmiar
//float Max(ciag geometryczny, int rozmiar);

// Funkcja sluzy do wyboru funkcji ,ktorej wartosc chcemy zwrocic
// Przyjmuje jako argument wskaznik do funkcji zwracajacej float, wskaznik do tablicy floatow oraz jej rozmiar
float Wykonaj(operacja op,ciag geometryczny,rozmiarCiagu rozmiar);