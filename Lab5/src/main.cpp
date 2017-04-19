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

    int ilosc_powtorzen=POWTORZENIA;

    wariant zmienna;

    bool pomoc;
    char wybor;
    cout << "1.losowy" << endl << "2.rosnacy" << endl << "3.malejacy" << endl << "0.zakoncz" <<endl;
    cin >> wybor;
    while(wybor!='0') {
        if(wybor=='1'){
            zmienna=losowy;
            pomoc=true;
        }
        else if(wybor=='2'){
            zmienna=rosnacy;
            pomoc=true;
        }
        else if(wybor=='3'){
            zmienna=malejacy;
            pomoc=true;
        }
        else{
            cout << "Zla opcja, sprobuj jeszcze raz" << endl;
            pomoc=false;
        }
        if(pomoc==true){
            zapisywanie_quicksortu(Miernik,obiekt,ilosc_powtorzen,zmienna);
        }
        cout << "1.losowy" << endl << "2.rosnacy" << endl << "3.malejacy" << endl << "0.zakoncz" << endl;
        cin >> wybor;
    }
    return 0;
}
