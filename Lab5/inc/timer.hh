#ifndef TIMER_HH
#define TIMER_HH

#include <ctime>
#include <cmath>
#include "array.hh"
#include "wariant.h"

class stoper{
    private:

        clock_t poczatek;
        clock_t koniec;
        
        double* czasy;
        double srednia;

        void start(){poczatek=clock();}
        void stop(){koniec=clock();}


    public:
        stoper():poczatek(0),koniec(0){
            srednia=0;
            czasy = NULL;
        }

        void mierz_czas(wykonywalny& Obiekt, int& rozmiar_problemu,int& ilosc_powtorzen,wariant& wybor);
        
        //metody get
        double gCzasy(int& index){return czasy[index];}
        double gSrednia(){return srednia;}

        void reset();//po wykonanych pomiarach trzeba zresetowac stoper
};











#endif
