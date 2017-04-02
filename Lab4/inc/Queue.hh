#ifndef QUEUE_HH
#define QUEUE_HH

#include "iQueue.hh"
#include "Node.hh"

class Queue:public iQueue{
    Node* first;
    Node* last;
public:
    virtual unsigned int size()=0;
    virtual bool enqueue(int element)=0;
    virtual bool dequeue()=0;

};

#endif