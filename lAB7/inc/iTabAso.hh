//
// Created by maciek on 27.04.17.
//

#ifndef LAB7_ITABASO_HH
#define LAB7_ITABASO_HH

#include "zalaczniki.hh"

class iTabAso {
public:
    iTabAso(){};
    virtual ~iTabAso(){};

    const virtual int& operator[](std::string)const =0;
    virtual void put(std::string,Wartosc)=0;

    virtual int rozm()=0;

//    cos mialo z tego byc ale nie ogarnalem
//    virtual void print(std::ostream& gdzie)=0;
};


//jakis pomysl ale nie do konca jasny
//std::ostream& operator << (std::ostream& StrmWy,iTabAso& Arg){
//    Arg.print(StrmWy);
//    return StrmWy;
//}


#endif //LAB7_ITABASO_HH
