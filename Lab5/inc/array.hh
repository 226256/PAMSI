#ifndef ARRAY_HH
#define ARRAY_HH

#include <iostream>
#include <ctime>
#include <cstdlib>


#include "wykonywalny.hh"
#include "wariant.h"


typedef int T;


class tablica : public wykonywalny{

    private:

        T* a;
        unsigned int asize;

         bool more(unsigned int rozmiar);
        


    public:
        tablica();
        tablica(unsigned int rozmiar);
        ~tablica();
  
        unsigned int sizeofarray(){
                return asize;
            }


         void saveinarray(unsigned int index,T val);
        T loadfromarray(unsigned int index);
         void reset();
         bool more1();
         bool more2n();



        virtual void wykonaj_algorytm(unsigned int& rozmiar_problemu,wariant wybor);
       unsigned int point(unsigned int l, unsigned int r);
      void quicksort(unsigned int l, unsigned int r);
      unsigned int divide_the_array(unsigned int l, unsigned int r);
      void change_places(unsigned int i2, unsigned int i1);
};















#endif
