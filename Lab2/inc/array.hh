#ifndef ARRAY_HH

#define ARRAY_HH

#include <iostream>



template<typename T>
class tablica{
    T* tab;
    unsigned int rozmiar;


    public:
        tablica(){
        rozmiar=0;
        tab=NULL;
        //tutaj konstruktor bezparametryczny
        }


        tablica(unsigned int& rozm){
        /*
        Tutaj konstruktor, ktory jako parametr przyjmuje rozmiar tablicy ktora potrzebujemy

        Tworzymy wskaznik na nowa tablice, adres ze wskaznika przypisuje do tab

        */
        rozmiar=rozm;
        T* temp=new T [rozmiar];
        tab=&temp;
        }



        unsigned int rozm(){
        return rozmiar;
        }




        void zapisanie_elementu(unsigned int& indeks,T& wartosc);
        T odczytanie_elementu(unsigned int& indeks);

    private:

        T* powieksz_tablice(unsigned int& rozmiar,T* stara_tablica);
        T* pomniejsz_tablice(unsigned int& rozmiar,T* stara_tablica);





};















#endif
