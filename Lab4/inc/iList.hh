#ifndef ILIST_HH
#define ILIST_HH

#include "Node.hh"

class iList{

public:
    virtual bool add(Node* element,int& position)=0;
    virtual bool rm(int& position)=0;
    virtual Node* get(int& postition)=0;
    virtual unsigned int size()=0;
    virtual int find(int& identificator)=0;
};

#endif