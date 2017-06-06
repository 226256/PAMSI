//
// Created by maciek on 31.05.17.
//

#include "../inc/Siec.hh"

//------------konstrukory i destruktory--------

Siec::Siec() {}

Siec::~Siec() {
    delete[](this->SpisPrzystankow);
}

//--------------------------------------------


Przystanek *Siec::ZnajdzNajkrotszaDroge(std::string &Poczatek, std::string &Koniec) const {
    //TODO tutaj stowrzyc algorytm wyszukiwania najkrotszej sciezki i zwracania tablicy z przystankami jakie trzeba odwiedzic

}
