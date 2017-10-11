//
// Created by maciek on 27.04.17.
//

#ifndef ITABASO_HH
#define ITABASO_HH

#include "zalaczniki.hh"
#include "Node.hh"

class iTabAso {
public:
    iTabAso(){};
    virtual ~iTabAso(){};

    virtual const int operator[](std::string)=0;
    virtual void put(std::string,Wartosc,Wariant)=0;
    virtual Para* search(std::string)=0;
    virtual int rozm()=0;
    virtual int ilewolnych()=0;



//    cos mialo z tego byc ale nie ogarnalem
//    virtual void print(std::ostream& gdzie)=0;
};


//jakis pomysl ale nie do konca jasny
//std::ostream& operator << (std::ostream& StrmWy,iTabAso& Arg){
//    Arg.print(StrmWy);
//    return StrmWy;
//}


#endif //LAB7_ITABASO_HH
