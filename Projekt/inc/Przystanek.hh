//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_PRZYSTANEK_HH
#define PROJEKT_PRZYSTANEK_HH

#include <list>
#include <string>
#include "Rozklad.hh"

class Przystanek {
private:
    std::string nazwa;
    unsigned int* numery_linii;
    std::list<Rozklad> lista;

public:
    Przystanek(const std::string &nazwa, unsigned int *numery_linii, const std::list<Rozklad> &lista);
//tylko konstruktor tworzacy pelny przystanek

    const std::string &getNazwa() const;

};


#endif //PROJEKT_PRZYSTANEK_HH
