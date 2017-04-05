#ifndef ILIST_HH
#define ILIST_HH

#include <iostream>

#include "Node.hh"

class iList{

public:

    virtual bool add(unsigned int& position,int value)=0;
    virtual bool rm(unsigned int& position)=0;
    virtual Node* get(unsigned int& postition)=0;
    virtual unsigned int size()=0;
    virtual Node* find(int& identificator)=0;
    virtual void do_algorithm()=0;
};

#endif