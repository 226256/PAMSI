//
// Created by maciek on 31.05.17.
//

#include "../inc/Rozklad.hh"

int Rozklad::getLinia() const {
    return linia;
}

int *Rozklad::getId_nastepnych() const {
    return id_nastepnych;
}

int *Rozklad::getCzas() const {
    return czas;
}
