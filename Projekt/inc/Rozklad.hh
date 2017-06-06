//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_ROZKLAD_HH
#define PROJEKT_ROZKLAD_HH

#include "zalaczniki.hh"

class Rozklad {
private:
    int linia;
    std::string wariant;
    int* id_nastepnych;
    int* czas;
public:
    Rozklad(int linia, const std::string &wariant, int *id_nastepnych, int *czas);
    virtual ~Rozklad();

    //----metody get---
    int getLinia() const;
    const std::string &getWariant() const;
    int *getId_nastepnych() const;
    int *getCzas() const;
    //-----------------


    bool operator==(const int  &rhs) const;
    bool operator!=(const int &rhs) const;
};


#endif //PROJEKT_ROZKLAD_HH
