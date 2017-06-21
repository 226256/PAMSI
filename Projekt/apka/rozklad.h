#ifndef ROZKLAD_H
#define ROZKLAD_H

#include "zalaczniki.h"


/*
 *  Kazdy rozklad wyglada tak ze jest numer linii
 *  wariant to nazwa trasy(np BISKUPIN, OPOROW,ZAJEZDNIA OŁBIN)
 *  id to tablica 2-elementkwa w ktorym jest id pierwszej znalezionej trasy w pliku,
 *
 *  idspec to jest tak ze sa linie typu K,C czy 900a wiec trzeba cos wymyslic:
 *      -jesli jest normalna linia(10,33,114) to numer to id a idspec to srednik(;)
 *      -jesli linia typu K,C itd to numer id to 1111, idspec to wlasnie litera z linia
 *      -jesli linia 0p no to wiadomo jak, 0 w idnum a p w idspec
 *      -jesli linia 900p to analogicznie do powyzszego
 *
 *  tylko po to zeby zebrac jakiekolwiek informacje o trasie
 *  id nastepnych to juz do wyszukiwania nastepnych przystankow
 *  czas to samo
 *
 */


class Rozklad {
private:
    int linia;
    char idspec;

    std::string wariant;
    int* idnum;

    //w tablicy z id nastepnych, w pierwszej komorce jest dlugosc calej tablicy(ilosc przystankow +1)
    int* id_nastepnych;
//    int* czas;

public:
    Rozklad(int* idtab,int lin,char znak,std::string Arg,int* tab);

    Rozklad(int linia, char idspec);

//    Rozklad(int linia, const std::string &wariant, int *id_nastepnych, int *czas);
    virtual ~Rozklad();

    //----metody get---

    //-----------------


//    bool operator==(const int  &rhs) const;
//    bool operator!=(const int &rhs) const;

    int getLinia() const;

    char getIdspec() const;

    const std::string &getWariant() const;

    int *getIdnum() const;

    int *getId_nastepnych() const;
    int IloscPrzystankowWLinii() const;

//    int *getCzas() const;
};


#endif // ROZKLAD_H
