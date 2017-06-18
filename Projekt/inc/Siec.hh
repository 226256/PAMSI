//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_SIEC_HH
#define PROJEKT_SIEC_HH

#include "Przystanek.hh"


/*
 * Film na yt Patrick Winston
 *
 *
 */

class Siec {
private:

    //Robie z tablica bo wydaje mi sie najszybszy dostep a niestety nie ogarnalem kontenera map
    Przystanek** SpisPrzystankow;
    Rozklad** SpisLinii;
    int IloscPrzystankow;
    int** macierz;

public:
    Siec();
    virtual ~Siec();

    void setSpisPrzystankow(Przystanek **SpisPrzystankow);
    void setIloscPrzystankow(int IloscPrzystankow);
    void setSpisLinii(Rozklad **SpisLinii);

    void wypisz();

    int getIloscPrzystankow() const;

    Rozklad **getSpisLinii() const;

    Przystanek* ZnajdzPrzystanek(std::string)const;
    Przystanek* ZnajdzPrzystanek(int id) const;
    Przystanek* ZnajdzPrzystanek(std::string Arg, int tabID) const;
    Przystanek** ZnajdzNajkrotszaDroge(std::string Poczatek,std::string Koniec) const;

};


#endif //PROJEKT_GRAF_HH