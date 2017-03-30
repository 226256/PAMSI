#ifndef ISTACK_HH
#define ISTACK_HH

class iStack{

public:
    virtual void/*unsigned int*/ size()=0;
    virtual int push(int element)=0;
    virtual void pop()=0;

};







#endif