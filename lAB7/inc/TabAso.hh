//
// Created by maciek on 27.04.17.
//

#ifndef LAB7_TABASO_HH
#define LAB7_TABASO_HH

#include "iTabAso.hh"
#include "Node.hh"

class TabAso:
        public iTabAso
{
    Para* tablica;
    int rozmiar;
    void h(std::string&);
public:
    TabAso();
    ~TabAso();

    //przeciazenie pozwalajace uzyskac element znajdujacy sie na miejscu
    // oznaczonym kluczem podawanym jako argument
    const int& operator [] (std::string) const;

    //metoda zwracajaca rozmiar tablicy
    int rozm();

    //dodawanie do tablicy
    void put(std::string,Wartosc);

    //przeblysk mysli ale nie wiedzialem jak rozwiazac
    //void print(std::ostream&);
};


#endif //LAB7_TABASO_HH
