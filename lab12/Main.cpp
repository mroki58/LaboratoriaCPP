// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o wykorzystanie kodu programu z wcześniejszych zajęć
// Klasy Line która reprezentuje linię,
// wg. matetycznego równania: y = a *x + b, oraz pozwala na wyliczania
// wartości operatorem (), i punktu przecięcia z osią odcietych (x'ów) wg równania
// x0 = - b / a;
// Oraz klasy LArray która pozwala przechowywać jako tablicę
// obiekty klasy Line; Uwaga: tablica LArray powinna być dynamicznie alokowana,
// z wykorzystaniem argumentu konstruktora odpowiadającemu za rozmiar tablicy.
//
// Należy uzupełnić implementację zadania o klasę LArraySmartPtr, która w rzeczywistości
// może odpowiadać tzw. std::shared_ptr, ogólnie sprytny wskaźnik.
// Funkcjonalność LArraySmartPtr opiera się o następujące założenia:
// Klasa LArraySmartPtr przechowuje wskaźnik do klasy LArray, oraz liczbę takich odniesień,
// tzn. liczbę kopii LArraySmartPtr, z których każda wskazuje na ten sam obiekt LArray.
// W przypadku gdy liczba takich odniesień zostaje zredukowana do 0 to LArraySmartPtr
// odpowiada za zwolnienie wskazywanego zasobu klasy LArray.
// Oczywiście, należałoby pamiętać o zasadzie 0/3/5,
// co jednak do poprawności tego zadania nie jest niezbędne.

// Kluczowe elementy zadania:
// I. inkrementacja _refCount
// 1/ Konstruktor kopiujący
// 2/ LArraySmartPtr& operator = (const LArraySmartPtr&)
// II. zwalnianie pamieci
// 3/ ad.I.2.
// 4/ Destruktor

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab12/
// * archiwum nie powinno zawierać katalogu build/

#include "Line.h"
#include <vector>
#include <algorithm>

std::ostream & operator<<(std::ostream & out, const LArray & arr)
{
    LPrint printline;
    printline(arr);
    return out;
}// Wkladalismy te funkcje do wszystkich plikow i z jakiego powodu nie byla widzialna
// Globalnie. Ustalilismy z Panem prowadzacym, ze wstawie to tutaj z notka dla Pana

int main (){
  Line fa(1,2);			          // y = 1*x + 2
  std::vector<Line> lines = { fa, 2};
  auto arr = new LArray(lines.size());

  auto addLine = [&](const Line& line){ // Funkcja Lambda
    arr->Add(line);
  }; 
  std::for_each(lines.begin(), lines.end(), addLine); 
  std::cout << *arr << std::endl; // Przeciążony opertor << dla std::ostream

  // Inicjalizacja SmartPointer
  std::cout << "larray_sptr_1..." << std::endl;
  LArraySmartPtr larray_sptr_1(arr);
  std::cout << *larray_sptr_1 << std::endl;

  // Internal scope:
  {
    std::vector<Line> lines = {11,12,13};
    // Inicjalizacja kolejnego SmartPointer
    LArraySmartPtr larray_sptr_2(new LArray(lines.size()));
    std::for_each(lines.begin(), lines.end(), [&](const Line& line){
      larray_sptr_2->Add(line);
      }
    ); 
    std::cout << "larray_sptr_2..." << std::endl;
    std::cout << *larray_sptr_2 << std::endl;
    // Przypisanie wskaźnika:
    // larray_sptr_1 zwalnia* zasoby wcześniej przechowywane
    // *pytanie: co znaczy zwalnia?
    larray_sptr_1 = larray_sptr_2;
  } // Koniec internal scope

  std::cout << "larray_sptr_1..." << std::endl;
  std::cout << *larray_sptr_1 << std::endl;

	return 0;
}
/* wynik dzialania programu:
y = 1* x + 2    x0 = -2
y = 2* x + 2    x0 = -1
larray_sptr_1...
y = 1* x + 2    x0 = -2
y = 2* x + 2    x0 = -1
larray_sptr_2...
y = 11* x + 11  x0 = -1
y = 12* x + 12  x0 = -1
y = 13* x + 13  x0 = -1
larray_sptr_1...
y = 11* x + 11  x0 = -1
y = 12* x + 12  x0 = -1
y = 13* x + 13  x0 = -1
*/
