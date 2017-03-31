#ifndef ISTACK_HH
#define ISTACK_HH

#include "Node.hh"

class iStack{

public:
    virtual void/*unsigned int*/ size()=0;
    virtual bool push(Node& element)=0;
    virtual Node pop()=0;

};







#endif