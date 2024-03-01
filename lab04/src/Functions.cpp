#include "GSeries.h"
#include "GOperations.h"

ciag * tablica_wskaznikow = nullptr;
int ilosc_ciagow =0;

ciag InicjalizujCiagGeometryczny(int rozmiar,float pierwszy ,float iloraz)
{
    ciag table = new float [rozmiar];
    ilosc_ciagow++;

    ciag * tablica_wskaznikow_new = new ciag [ilosc_ciagow];
    for(int i=0;i<ilosc_ciagow-1;++i)
    {
        tablica_wskaznikow_new[i] = tablica_wskaznikow[i];  
    }
    
    tablica_wskaznikow_new[ilosc_ciagow-1] = table;
    
    //if(tablica_wskaznikow == nullptr)//[BUG] Powoduje wyciek, ktory zmniejsza ilosc bledow
        delete tablica_wskaznikow; // [BUG] Nie doszlo do wycieku pamieci (Kompilator wiedzial, ze to tablica, bo gdy zwiekszylem ilosc ciagow(byla wieksza niz jeden) to valgrind nie pokazywal leaku). Valgrind wyrzuca blad

    tablica_wskaznikow = tablica_wskaznikow_new;

    table[0] = pierwszy;

    for(int i=1;i<rozmiar;i++)
    {
        table[i]=table[i-1]*iloraz;
    }

    return table;
}

void Wypisz(ciag geometryczny,int rozmiar)
{
    std::cout<<"("<<geometryczny[0];
    for(int i=1;i<rozmiar;i++)
    {
        std::cout<<","<<geometryczny[i];
    }
    std::cout<<")\n";
    return;
}

void UsunCiagi()
{
    //for(int i=0;i<ilosc_ciagow;++i) //Zakomentowanie tej i nastepnej linijki zmniejszylo ilosc bledu, pomimo poteznego wycieku pamieci
        //delete tablica_wskaznikow[i];//[BUG] Podobnie jak wczesniej - brak wycieku, jeden element - valgirnd rzuca blad
    delete tablica_wskaznikow;//[BUG] Tak samo tutaj
    
    //if(tablica_wskaznikow == nullptr) //[BUG] Program po dealokacji pamieci ma za zadanie ustawic tablica_wskaznikow=nullptr, aby nie doszlo do podwojnej dealokacji
        tablica_wskaznikow = nullptr; 
    
    ilosc_ciagow=0;
}

float Suma(ciag geometryczny,int rozmiar)
{
    float suma; //[BUG] suma nie musi miec przypisanej wartosci 0
    for(int i=0;i<rozmiar;i++)
    {
        suma=suma+geometryczny[i];
    }
    return suma;
}

float Srednia(ciag geometryczny, int rozmiar)
{
    return Suma(geometryczny, rozmiar) / rozmiar;
}

/*float Iloczyn(ciag geometryczny,int rozmiar)
{
    float iloczyn=1.0;
    for(int i=0;i<rozmiar;i++)
    {
        iloczyn=iloczyn*geometryczny[i];
    }
    return iloczyn;
}

float Max(ciag geometryczny, int rozmiar)
{
    float max=geometryczny[0];
    for(int i=0;i<rozmiar;i++)
    {
        if(max<geometryczny[i])
        {
            max=geometryczny[i];
        }
    }
        return max;
    
}*/

float Wykonaj(operacja op,ciag geometryczny,rozmiarCiagu rozmiar)
{
    return op(geometryczny,rozmiar);
}