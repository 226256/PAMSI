//
// Created by maciek on 18.05.17.
//

#ifndef LAB8_BST_HH
#define LAB8_BST_HH

#include "Testowalny.hh"
#include "iTree.hh"
#include "TreeNode.hh"

class bst :
        public iTree,
        public Testowalny{
    TreeNode* root;
    int rozmiar;
public:
    bst();
    ~bst();
    int size();
    bool isEmpty();
    TreeNode* TreeSearch(int& klucz);
    void TreeAdd(int& klucz,Wartosc& Dane);

    void TreeAdd(int &klucz) override;

    void TreeRemove(int& klucz);
    TreeNode *getRoot() const;
    void setRoot(TreeNode *root);


};


#endif //LAB8_BST_HH
