//
// Created by Maciek on 27.04.17.
//

#ifndef LAB7_TABASO_HH
#define LAB7_TABASO_HH

#include "iTabAso.hh"
#include "Testowalny.hh"
#include "Node.hh"
#include "exceptions.hh"



/*
 * Tablica asocjacyjna z liniowym rozwiazaniem problemu kolizji
 * TODO zrobic mozliwosc wyboru sposobu haszowania
 */

class TabAso:
        public iTabAso,
        public Testowalny
{
    Para** tablica;
    int rozmiar;
    int wolnemiejsca;
    int h(std::string&);
    int h2(std::string&);
public:
    TabAso();
    TabAso(int rozm);
    ~TabAso();

    //przeciazenie pozwalajace uzyskac element znajdujacy sie na miejscu
    // oznaczonym kluczem podawanym jako argument
    const int operator [] (std::string) ;

    //metoda zwracajaca rozmiar tablicy
    int rozm();

    //metoda mowiaca ile wolnych miejsc jest jeszcze w tablicy
    int ilewolnych();

    //dodawanie do tablicy
    void put(std::string,Wartosc,Wariant);

    Para* search(std::string);

    //przeblysk mysli ale nie wiedzialem jak rozwiazac
    //void print(std::ostream&);

    void zbuduj(std::string,int wartosc,Wariant hasz);
    void zadanie(std::string);
    void reset();
};


#endif //LAB7_TABASO_HH
