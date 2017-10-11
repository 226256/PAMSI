#ifndef ARRAY_HH
#define ARRAY_HH

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>


#include "wykonywalny.hh"
#include "wariant.h"


typedef int T;


class tablica : public wykonywalny{

    private:

        T* a;
         int asize;

         bool more( int rozmiar);
        


    public:
        tablica();
        tablica( int rozmiar);
        ~tablica();
  
         int sizeofarray(){
                return asize;
            }


         void saveinarray( int index,T val);
        T loadfromarray( int index);
         void reset();
         bool more1();
         bool more2n();



        virtual void wykonaj_algorytm( int& rozmiar_problemu,wariant wybor);
       int indpiwota( int l,  int r);
      void quicksort( int l,  int p);
       int divide_the_array( int l,  int r);
      void change_places( int i2,  int i1);
};















#endif
