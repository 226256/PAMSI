//
// Created by maciek on 06.05.17.
//

#ifndef LAB7_MIERNIK_HH
#define LAB7_MIERNIK_HH

#include "zalaczniki.hh"
#include "TabAso.hh"

class Miernik {
    clock_t poczatek;
    clock_t koniec;
    double* czasy;
    double srednia;
    int rozm;

    void start();
    void stop();
public:
    Miernik();
    Miernik(int ilepomiarow);
    ~Miernik();
    void resetuj(int ilepomiarow);

    double wezsredni();

    void mierzczas(Testowalny&,std::string stringdotestow,int wartoscdotestu,int nrokrazenia,Wariant);
};


#endif //LAB7_MIERNIK_HH
