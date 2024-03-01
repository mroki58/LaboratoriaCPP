#pragma once
#include "Point3D.h"

class VPointCloud{
public:
    
    VPointCloud() = default;

    // Dodaje wskaznik do dynamicznie zaalokowanego elementu point
    // do _vector
    void addPoint(Point3D * point);

    // Dodaje wskaznik do dynamicznie zaalokowanego elementu
    // o wartosciach takich samych jak przekazanych w std::array point
    void addPoint(std::array<double,3> point);

    // Wypisuje w zadanym formacie
    void displayPoints();

    // Zwraca ptr na kopię punktu przechowywanego pod indeksem = i
    Point3D * getCopyPoint(int i);

    
    // Dodaje zawartosc tablicy cloud do _vector 
    // Alokuje pamiec na nowe element o takich samych wartosciach jak tych w cloud
    // Blokuje mozliwosc dodania _vector na koniec _vector
    void add(const VPointCloud & cloud);

    //Konstruktor przenoszacy
    VPointCloud(VPointCloud && cloud);
  
    //Destruktor zwalniajacy pamiec
    ~VPointCloud();

private:
    std::vector<Point3D *> _vector;

};