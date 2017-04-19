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
/*   manualnie w pliku wariant.hh                       */
/*   ROZMIAR,ROZMIAR_PROBLEMU oraz ILOSC_POWTORZEN      */
/********************************************************/



int main(){
    stoper Miernik;
    tablica obiekt(ROZMIAR);

     int problem=ROZMIARPROBLEMU;
    int ilerazy=POWTORZENIA;


    cout << "Tablica z elementami: " << obiekt.sizeofarray() << endl;

    for( int i=0;i<ROZMIAR;i++){
        T temp=rand()%ROZMIAR;
        obiekt.saveinarray(i,temp);
    }
//    for( int i=0;i<ROZMIAR;i++){
//        cout << obiekt.loadfromarray(i) << '\t';
//    }

    obiekt.quicksort(0,ROZMIAR-1);
//    for( int i=0;i<ROZMIAR;i++){
//        cout << obiekt.loadfromarray(i) << endl;
//    }

    return 0;
}
