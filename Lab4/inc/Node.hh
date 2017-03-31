#ifndef INODE_HH
#define INODE_HH

#include <iostream>

class Node{
    int element;
    Node* next;
    Node* prev;
public:
    Node():element(0),next(NULL),prev(NULL){}
    ~Node(){}

};

#endif