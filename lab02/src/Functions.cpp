#include "GSeries.h"
#include "GOperations.h"

ciag * tablica_wskaznikow = nullptr;
int ilosc_ciagow =0;

ciag InicjalizujCiagGeometryczny(int rozmiar, float iloraz)
{
    ciag table = (ciag) malloc(sizeof(float)*rozmiar);
    ilosc_ciagow++;
    tablica_wskaznikow =(ciag *) realloc(tablica_wskaznikow,ilosc_ciagow*sizeof(float*));
    tablica_wskaznikow[ilosc_ciagow-1] = table;

    table[0]=1.0;

    for(int i=1;i<rozmiar;i++)
    {
        table[i]=table[i-1]*iloraz;
    }

    return table;
}

void Wypisz(ciag geometryczny,int rozmiar)
{
    printf("(%.f",geometryczny[0]);
    for(int i=1;i<rozmiar;i++)
    {
        printf(",%.f",geometryczny[i]);
    }
    printf(")\n");
    return;
}

void UsunCiagi()
{
    for(int i=0;i<ilosc_ciagow;i++)
    {
        free(tablica_wskaznikow[i]);
    }
    free(tablica_wskaznikow);
}

float Suma(ciag geometryczny,int rozmiar)
{
    float suma=0.0;
    for(int i=0;i<rozmiar;i++)
    {
        suma=suma+geometryczny[i];
    }
    return suma;
}

float Iloczyn(ciag geometryczny,int rozmiar)
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
    
}

float Wykonaj(operacja op,ciag geometryczny,rozmiarCiagu rozmiar)
{
    return op(geometryczny,rozmiar);
}