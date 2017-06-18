#ifndef ARRAY_HH

#define ARRAY_HH

#include <iostream>



typedef int T;


class array{

    private:

        T* a;
        unsigned int asize;


        bool more(unsigned int rozmiar);
        bool fewer(unsigned int as);




    public:



        array(){
                asize=0;
                a=NULL;
        //tutaj konstruktor bezparametryczny
            }


        array(unsigned int as){
        /*
        Tutaj konstruktor, ktory jako parametr przyjmuje rozmiar tablicy ktora potrzebujemy

        Tworzymy wskaznik na nowa tablice, adres ze wskaznika przypisuje do tab

        */
                asize=as;
                T* temp=new T [asize];
                a=temp;
            }

        ~array(){
        delete [] a;
        asize=0;
        }


        unsigned int sizeofarray(){
                return asize;
            }




        void saveinarray(unsigned int index,T val);
        T loadfromarray(unsigned int index);

        bool more1();
        bool more2n();

};















#endif
