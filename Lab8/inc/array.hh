#ifndef ARRAY_HH
#define ARRAY_HH


#include "zalaczniki.hh"




class tablica{

    private:
        Wartosc * a;
        unsigned int asize;
         bool more(unsigned int rozmiar);

    public:
        tablica();
        tablica(unsigned int rozmiar);
        ~tablica();
  
        unsigned int sizeofarray(){
                return asize;
            }


         void saveinarray(unsigned int index,Wartosc val);
        Wartosc loadfromarray(unsigned int index);
         bool more1();
         bool more2n();



};















#endif
