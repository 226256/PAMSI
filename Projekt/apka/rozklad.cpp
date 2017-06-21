#include "rozklad.h"


Rozklad::Rozklad(int* idtab, int lin, char znak,std::string Naz,int* tab) : idnum(idtab),linia(lin),idspec(znak),wariant(Naz),id_nastepnych(tab) {}


//Rozklad::Rozklad(int linia, const std::string &wariant, int *id_nastepnych, int *czas) : linia(linia), wariant(wariant),
//                                                                                         id_nastepnych(id_nastepnych),
//                                                                                         czas(czas) {}
Rozklad::Rozklad(int linia, char idspec) : linia(linia), idspec(idspec) {}

Rozklad::~Rozklad() {
    delete [] this->id_nastepnych;
//    delete [] this->czas;
}

//--------metody get---------------------------------
int Rozklad::getLinia() const {
    return linia;
}

char Rozklad::getIdspec() const {
    return idspec;
}

const std::string &Rozklad::getWariant() const {
    return wariant;
}

int *Rozklad::getIdnum() const {
    return idnum;
}

int *Rozklad::getId_nastepnych() const {
    return id_nastepnych;
}

int Rozklad::IloscPrzystankowWLinii() const {
    return this->id_nastepnych[0];
}
//
//int *Rozklad::getCzas() const {
//    return czas;
//}
//----------------------------------------------------


//
//bool Rozklad::operator==(const int &rhs) const {
//    return rhs==this->linia;
//}
//
//bool Rozklad::operator!=(const int &rhs) const {
//    return rhs != this->linia;
//}
//
