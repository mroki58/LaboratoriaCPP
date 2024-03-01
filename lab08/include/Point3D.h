#pragma once
#include <iostream>
#include <array>
#include <vector>
#include <iomanip>

class VPointCloud;

class Point3D{
friend class VPointCloud;
public:

    // Konstruktory - inicjalizuja wartosci elementow std::array _cords
    // Jako argument moze przyjac std::array<double,3> table
    Point3D(std::array<double,3> table = {0.0, 0.0, 0.0});

    // Konstruktor, ktory deleguje konstruktor powyzej do inicjalizacji
    // calej tablicy _cords wartoscia x
    Point3D(double x): Point3D({x,x,x}) {}

    // Wypisuje zawartosc _cords w formacie (_cords[0],_cords[1],_cords[2])
    void displayCoordinates() const;

    static int DISPLAY_PRESITION;

private:

    std::array<double,3> _cords;

};