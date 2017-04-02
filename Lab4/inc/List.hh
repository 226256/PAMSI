#ifndef LIST_HH
#define LIST_HH

#include "iList.hh"
#include "Node.hh"

class List : public iList{
    Node* head;
    Node* tail;
    unsigned int amount;

public:
    List();
    ~List();

    bool add(unsigned int& position);
    bool rm(unsigned int& position);
    Node* get(unsigned int& postition);
    unsigned int size();
    int find(int& identificator);
};

#endif