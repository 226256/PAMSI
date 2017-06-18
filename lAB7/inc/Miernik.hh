//
// Created by maciek on 06.05.17.
//

#ifndef MIERNIK_HH
#define MIERNIK_HH

#include "zalaczniki.hh"
#include "TabAso.hh"

class Miernik {
    clock_t poczatek;
    clock_t koniec;
    long double* czasy;
    long double srednia;
    int rozm;

    void start();
    void stop();
public:
    Miernik();
    Miernik(int);
    ~Miernik();
    void resetuj(int);

    long double wezsredni();

    void mierzczas(Testowalny&,std::string stringdotestow,int wartoscdotestu,int nrokrazenia,Wariant);
    void zapis_do_pliku(Wariant&);
};


#endif //LAB7_MIERNIK_HH
