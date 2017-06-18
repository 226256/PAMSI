//
// Created by maciek on 08.05.17.
//

#ifndef TESTOWALNY_HH
#define TESTOWALNY_HH

#include "zalaczniki.hh"

class Testowalny {
public:
    virtual ~Testowalny(){};
    virtual void zbuduj(std::string dotestow,int wartosc,Wariant hasz)=0;
    virtual void zadanie(std::string dotestow="",int wartosc=0)=0;
};


#endif //LAB7_TESTOWALNY_HH
