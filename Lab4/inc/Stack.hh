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

    virtual void/*unsigned int*/ size(){};
    virtual int/*iStack*/ push(int element){int temp=2; return temp+element;};
    virtual void/*iStack*/ pop(){};


};

#endif