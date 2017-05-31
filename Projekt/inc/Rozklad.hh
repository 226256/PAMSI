//
// Created by maciek on 31.05.17.
//

#ifndef PROJEKT_ROZKLAD_HH
#define PROJEKT_ROZKLAD_HH


class Rozklad {
    int linia;
    int* id_nastepnych;
    int* czas;
public:
    int getLinia() const;
    int *getId_nastepnych() const;
    int *getCzas() const;

};


#endif //PROJEKT_ROZKLAD_HH
