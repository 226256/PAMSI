//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_PRZYSTANEK_HH
#define PROJEKT_PRZYSTANEK_HH


#include "Rozklad.hh"
#include <cmath>

class Przystanek {
private:
    int id;
    std::string nazwa;
    double lat;
    double lon;

    int ilosc_linii;
    int* numery_linii;
    Rozklad** TablicaPoszczegolnychRozkladow;

    std::list<Przystanek*> Sasiedzi;
    double koszt;
    Przystanek* rodzic;

public:
    //------konstruktory i destruktor---------
    Przystanek(const std::string &nazwa,int& idNowego);

    Przystanek(int id, const std::string &nazwa, double lat, double lon);

    Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii, Rozklad **TablicaPoszczegolnychRozkladow);
    virtual ~Przystanek();
    //----------------------------------------


    //----metody get i set-------------------
    const std::string &getNazwa() const;
    int *getNumery_linii() const;
    int getId() const;

    double getLat() const;

    double getLon() const;

    double getKoszt() const;
    Przystanek *getRodzic() const;

    void setRodzic(Przystanek *Rodzic);

    //---------------------------------

    Rozklad* ZnajdzLinie(int)const ;
    Rozklad* ZnajdzLinie(std::string)const;
    void WyliczKoszt(double szerokosc, double dlugosc);
    void DodajSasiada(Przystanek* Arg);
};


#endif //PROJEKT_PRZYSTANEK_HH
