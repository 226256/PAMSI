#ifndef WYKONYWALNY_HH
#define WYKONYWALNY_HH
#include "wariant.h"



class wykonywalny{
    public:
    virtual ~wykonywalny(){}
    virtual void wykonaj_algorytm( int& rozmiar_problemu,wariant wybor)=0;
    
    /*potrzebna mi metoda ktora,np dla tablicy
      bedzie resetowala mi obiekt do stanu pierwotnego 
      po wykonaniu powiekszania, bo dla duzych powiekszen
      brak resetowania moze wplywac na czas lgorytmu*/
    virtual void reset()=0;
    virtual void quicksort(int l,int p)=0;
};












#endif
