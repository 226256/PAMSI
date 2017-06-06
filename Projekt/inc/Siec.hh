//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_SIEC_HH
#define PROJEKT_SIEC_HH

#include "Przystanek.hh"


class Siec {
private:
    Przystanek* SpisPrzystankow;
    unsigned iloscprzystankow;
public:
    Siec();
    virtual ~Siec();

    Przystanek* ZnajdzNajkrotszaDroge(std::string& Poczatek,std::string& Koniec) const;

};


#endif //PROJEKT_GRAF_HH
