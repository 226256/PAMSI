#ifndef IQUEUE_HH
#define IQUEUE_HH

#include "Node.hh"

class iQueue{

public:
    virtual unsigned int size()=0;
    virtual bool enqueue(Node* element)=0;
    virtual Node* dequeue()=0;

};

#endif