#ifndef ISTACK_HH
#define ISTACK_HH

class iStack{

public:
    virtual unsigned int size()=0;
    virtual iStack push(iStack element)=0;
    virtual iStack pop()=0;

};







#endif