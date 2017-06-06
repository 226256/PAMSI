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

bool Rozklad::operator==(const int &rhs) const {
    return rhs==this->linia;
}

bool Rozklad::operator!=(const int &rhs) const {
    return rhs != this->linia;
}

Rozklad::Rozklad(int linia, const std::string &wariant, int *id_nastepnych, int *czas) : linia(linia), wariant(wariant),
                                                                                         id_nastepnych(id_nastepnych),
                                                                                         czas(czas) {}

Rozklad::~Rozklad() {
    delete [] this->id_nastepnych;
    delete [] this->czas;
}

const std::string &Rozklad::getWariant() const {
    return wariant;
}
