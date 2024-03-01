#pragma once
#include <iostream>
#include <array>
#include <vector>

class APointCloud;
class VPointCloud;

class Point3D{
friend class APointCloud;
friend class VPointCloud;
public:

    // Konstruktory - inicjalizuja wartosci elementow std::array _cords
    // Jako argument moze przyjac std::array<double,3> table
    Point3D(std::array<double,3> table = {0.0, 0.0, 0.0});

    // Wypisuje zawartosc _cords w formacie (_cords[0],_cords[1],_cords[2])
    void displayCoordinates() const;

private:

    std::array<double,3> _cords;

};

class APointCloud{
friend class VPointCloud;
public:
    // Konstruktor domyslny przypisujacy watrosci nullptr do _table
    // i 0 do _iter
    APointCloud();

    // Dodaje punkt point do dynamicznie zaalokowanej i realokowanej tutaj
    // pamieci podpietej do wskaznika _table o dlugosci _iter
    // _iter jest tutaj inkrementowane
    void addPoint(Point3D point);

    // Wypisuje wszystkie punkty w chmurze w zadanym formacie
    void displayPoints() const;

    // Zwraca wspolrzedne geometryczne punktu znajdujacego sie w geometrycznym
    // srodku wszystkich punktow w chmurze
    Point3D geoCentre();

    // Zwalnia pamiec zaalokowana w addPoint
    ~APointCloud();

private:
    Point3D * _table;
    int _iter;

};

class VPointCloud{
public:
    // Dodaje punkt point na koniec std::vector<Point3D> _vector
    void addPoint(Point3D point);

    // Dodaje chmure punktow cloud (typu VPointCloud)na koniec std::vector<Point3D>
    //_vector
    void add(const VPointCloud & cloud);

    // Dodaje chmure punktow cloud (typu APointCloud)na koniec std::vector<Point3D>
    //_vector
    void add(const APointCloud & cloud);

    // Zwraca wspolrzedne geometryczne punktu znajdujacego sie w geometrycznym
    // srodku wszystkich punktow w chmurze
    Point3D geoCentre();

    // Zwraca liczby calkowita oznaczajaca liczbe punktow w chmurze
    int count();

private:
    std::vector<Point3D> _vector;

};