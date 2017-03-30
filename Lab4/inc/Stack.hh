#ifndef STACK_HH
#define STACK_HH

#include "iStack.hh"



class Stack : public iStack{
    struct Node{
        int element;
        Node* next;
    };
    unsigned int amount;

public:

    virtual unsigned int size(){};
    virtual iStack push(int element){};
    virtual iStack pop(){};


};

#endif