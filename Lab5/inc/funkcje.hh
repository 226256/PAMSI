#ifndef FUNKCJE_HH
#define FUNKCJE_HH

#include "wykonywalny.hh"
#include "array.hh"
#include "timer.hh"
#include "wariant.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>


void zawody(stoper& Miernik,
            wykonywalny& Obiekt,
            int rozmiar_problemu,
            int ilosc_powtorzen);
            
void zapis_do_pliku(stoper& Dane,wariant& wybor);



void quicksort(tablica& obiekt,  int lewy, int prawy);


#endif