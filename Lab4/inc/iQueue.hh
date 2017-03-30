#ifndef IQUEUE_HH
#define IQUEUE_HH

class iQueue{

public:
    virtual unsigned int size()=0;
    virtual bool enqueue(int element)=0;
    virtual bool dequeue()=0;

};

#endif