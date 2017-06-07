//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_PRZYSTANEK_HH
#define PROJEKT_PRZYSTANEK_HH


#include "Rozklad.hh"

class Przystanek {
private:
    int id;
    std::string nazwa;
    int ilosc_linii;
    int* numery_linii;
    Rozklad** TablicaPoszczegolnychRozkladow;

public:
    //------konstruktory i destruktor---------
    Przystanek(const std::string &nazwa,int& idNowego);
    Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii, Rozklad **TablicaPoszczegolnychRozkladow);
    virtual ~Przystanek();
    //----------------------------------------


    //----metody get-------------------
    const std::string &getNazwa() const;
    int *getNumery_linii() const;
    int getId() const;
    //---------------------------------
    void wypisz();

    Rozklad* ZnajdzLinie(int)const ;
    Rozklad* ZnajdzLinie(std::string)const;
};


#endif //PROJEKT_PRZYSTANEK_HH
