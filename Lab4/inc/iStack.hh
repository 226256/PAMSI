#ifndef ISTACK_HH
#define ISTACK_HH

#include "Node.hh"
#include <iostream>

class iStack{

public:
    virtual unsigned int size()=0;
    virtual bool push(Node* element)=0;
    virtual Node* pop()=0;
    virtual void do_algorithm()=0;

};







#endif