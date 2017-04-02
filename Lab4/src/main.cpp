#include <iostream>
#include <cstdlib>

#include "iList.hh"
#include "iStack.hh"
#include "iQueue.hh"
#include "iClock.hh"
#include "Node.hh"
#include "Stack.hh"
#include "List.hh"
#include "Queue.hh"

using namespace std;


int main(){

    Node* head=new Node();
    Node* myNode=new Node;
    head->setNext(myNode);
    cout << head->getNext() << endl;


    return 0;
}