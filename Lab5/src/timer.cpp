#include "timer.hh"
#include "wykonywalny.hh"
#include "wariant.h"
#include <iostream>
#include <ctime>



void stoper::mierz_czas(wykonywalny& Obiekt, int& rozmiar_problemu,int& ilosc_powtorzen,wariant& wybor){

//tworze tymczasowa tablice w ktorej bede zapisywal poszczegolne wyniki
    double* tab=new double [ilosc_powtorzen];
    double suma=0;

//------mierze czasy wykonywania algorytmow n razy
    for(int i=0; i<ilosc_powtorzen;i++){
        start();
        Obiekt.wykonaj_algorytm(rozmiar_problemu,wybor);
        stop();
        tab[i]=(koniec-poczatek)/(double)CLOCKS_PER_SEC;
        Obiekt.reset();
    }

    this->czasy=tab;



    for(int i=0;i<ilosc_powtorzen;i++){
        suma+=tab[i];
        }
    this->srednia=suma/ilosc_powtorzen;

}


void stoper::reset(){
    czasy=NULL;
    srednia=0;
}


void stoper::sprawdz_algorytm(tablica& obiekt, int& ilosc_powtorzen, wariant& wybor){
    double* tab=new double [ilosc_powtorzen];
    double suma=0;

//    int problem=ROZMIARPROBLEMU;
    int rozmtablicy=obiekt.sizeofarray();

    for(int i=0;i<ilosc_powtorzen;i++){
        if(wybor==losowy) {
            for (int i = 0; i < ROZMIAR; i++) {
                T temp = rand() % ROZMIAR;
                obiekt.saveinarray(i, temp);
            }
        }
        else if(wybor==rosnacy){
            for (int i = 0; i < ROZMIAR; i++) {
                T temp = (T)i;
                obiekt.saveinarray(i, temp);
            }

        }
        else if(wybor==malejacy){
            for (int i = 0; i < ROZMIAR; i++) {
                T temp = (T)(ROZMIAR-i);
                obiekt.saveinarray(i, temp);
            }
        }

        start();
        obiekt.quicksort(0,rozmtablicy-1);
        stop();
        tab[i]=(koniec-poczatek)/(double)CLOCKS_PER_SEC;

    }

    this->czasy=tab;


    for(int i=0;i<ilosc_powtorzen;i++){
        suma+=tab[i];
    }
    this->srednia=suma/ilosc_powtorzen;

}