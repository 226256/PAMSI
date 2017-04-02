#ifndef STACK_HH
#define STACK_HH

#include "iStack.hh"
#include "Node.hh"

class Stack : public iStack{
    Node* element;
    unsigned int amount;

public:

    virtual void/*unsigned int*/ size(){};
    virtual bool push(Node& element){bool temp=true;return temp;};
    virtual Node pop(){Node temp; return temp;};


};

#endif