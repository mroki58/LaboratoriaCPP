#include "Ksztalt.h"
#define PI 3.1415

class Kolo: public Ksztalt{
public:    
    Kolo(double r = 0): _r(r) {}

    // Wypisuje wiadomosc o kole o promieniu _r
    void wypisz(std::ostream & out) const override;

    // Zwraca pole powierzchni kola
    double polePow() const override;

private:
    double _r;

};