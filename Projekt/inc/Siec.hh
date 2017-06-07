//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_SIEC_HH
#define PROJEKT_SIEC_HH

#include "Przystanek.hh"


class Siec {
private:

    //Robie z tablica bo wydaje mi sie najszybszy dostep a niestety nie ogarnalem kontenera map
    Przystanek** SpisPrzystankow;
    int IloscPrzystankow;

public:
    Siec();
    virtual ~Siec();

    void setSpisPrzystankow(Przystanek **SpisPrzystankow);
    void setIloscprzystankow(int iloscprzystankow);
    void wypisz();

    Przystanek* ZnajdzPrzystanek(std::string)const;
    Przystanek** ZnajdzNajkrotszaDroge(std::string Poczatek,std::string Koniec) const;

};


#endif //PROJEKT_GRAF_HH
