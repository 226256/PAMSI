#ifndef PRZYSTANEK_H
#define PRZYSTANEK_H

#include "rozklad.h"


class Przystanek {
private:
    int id;
    std::string nazwa;
    double lat;
    double lon;

    int ilosc_linii;
    int* numery_linii;
//    Rozklad** TablicaPoszczegolnychRozkladow;

    std::list<Przystanek*> Sasiedzi;
    std::list<int*> LinieJakiePrzejezdzajaPrzezPrzystanek;

    double koszt;
    double H;   //odleglosc od koncowego przystanku
    double G;   //odleglosc od rodzica
    Przystanek* rodzic = nullptr;

public:
    //------konstruktory i destruktor---------
    Przystanek(const std::string &nazwa,int& idNowego);

    Przystanek(int id, const std::string &nazwa, double lat, double lon);

//    Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii, Rozklad **TablicaPoszczegolnychRozkladow);
    virtual ~Przystanek();
    //----------------------------------------


    //----metody get-------------------
    const std::string &getNazwa() const;
    int *getNumery_linii() const;
    int getId() const;

    double getLat() const;

    double getLon() const;

    double getKoszt() const;
    double getG() const;
    double getH() const;
    Przystanek *getRodzic() const;

    const std::list<Przystanek *> &getSasiadow() const;
    //---------------------------------

//    Rozklad* ZnajdzLinie(int)const ;
//    Rozklad* ZnajdzLinie(std::string)const;
    void WyliczKoszt(double szerokosc, double dlugosc);
    void DodajSasiada(Przystanek* Arg);
    void DodajRodzica(Przystanek *Rodzic);

    void DodajLiniePrzejezdzajaca(int*);
};


#endif // PRZYSTANEK_H
