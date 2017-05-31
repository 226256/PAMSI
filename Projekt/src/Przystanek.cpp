//
// Created by maciek on 31.05.17.
//

#include "../inc/Przystanek.hh"

//-----------------------metody get------------




const std::string &Przystanek::getNazwa() const {
    return nazwa;
}

Przystanek::Przystanek(const std::string &nazwa, unsigned int *numery_linii, const std::list<Rozklad> &lista) : nazwa(
        nazwa), numery_linii(numery_linii), lista(lista) {}
//---------------------------------------------

