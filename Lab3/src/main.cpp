#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <ctime>

#include "array.hh"
#include "wykonywalny.hh"
#include "timer.hh"
#include "funkcje.hh"

using namespace std;


typedef int T;


/********************************************************/
/*   wszystkie potrzebne parametry zmienia sie          */
/*   manualnie w pliku wykonywalny.hh                   */                                                
/*   ROZMIAR,ROZMIAR_PROBLEMU oraz ILOSC_POWTORZEN      */
/********************************************************/



int main(){
  stoper Miernik;
  tablica obiekt(ROZMIAR);

  unsigned int problem=ROZMIARPROBLEMU;
  int ilerazy=POWTORZENIA;

  
  //funkcja ktorej definicja znajduje sie w pliku funkcje.cpp
  zawody(Miernik,obiekt,problem,ilerazy);




return 0;
}
