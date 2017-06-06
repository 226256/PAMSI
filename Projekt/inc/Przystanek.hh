//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_PRZYSTANEK_HH
#define PROJEKT_PRZYSTANEK_HH


#include "Rozklad.hh"

class Przystanek {
private:
    std::string nazwa;
    int ilosc_linii;
    int* numery_linii;
    Rozklad** TablicaPoszczegolnychRozkladow;

public:
    Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii, Rozklad **TablicaPoszczegolnychRozkladow);

    //tylko konstruktor tworzacy pelny przystanek
    virtual ~Przystanek();

    const std::string &getNazwa() const;
    Rozklad* ZnajdzLinie(int&)const ;

    int *getNumery_linii() const;


};


#endif //PROJEKT_PRZYSTANEK_HH
