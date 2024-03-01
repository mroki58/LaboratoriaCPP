#include "Ksztalt.h"

class Trojkat: public Ksztalt{
public:
    Trojkat(double a, double b, double c):_a(a), _b(b), _c(c) {}

    // Wypisuje wlasciwosci trojkata
    void wypisz(std::ostream & out) const override;

    // Zwraca pole powierzchni trojkata
    double polePow() const override;

private:
    double _a;
    double _b;
    double _c;

};