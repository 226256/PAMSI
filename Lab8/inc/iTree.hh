//
// Created by maciek on 18.05.17.
//

#ifndef ITREE_HH
#define ITREE_HH

#include "zalaczniki.hh"
#include "TreeNode.hh"

class iTree {
public:
    iTree(){}
    virtual ~iTree(){};

    virtual int size()=0;
    virtual bool isEmpty()=0;
    virtual TreeNode* TreeSearch(int& klucz)=0;
    virtual void TreeAdd(int& klucz)=0;
    virtual void TreeAdd(int& klucz,Wartosc& Dane)=0;
    virtual void TreeRemove(int& klucz)=0;

};


#endif //LAB8_ITREE_HH
