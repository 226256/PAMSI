//
// Created by maciek on 18.05.17.
//

#ifndef TREENODE_HH
#define TREENODE_HH

#include "zalaczniki.hh"

class TreeNode {
    TreeNode* przodek;
    TreeNode* LewySyn;
    TreeNode* PrawySyn;

    int klucz;
    Wartosc dane;
public:
    TreeNode();
    TreeNode(int&,Wartosc&);
    ~TreeNode();

    TreeNode* RightSon();
    TreeNode* LeftSon();
    TreeNode* Ancestor();

    void setRightSon(TreeNode*);
    void setLeftSon(TreeNode*);
    void setAncestor(TreeNode*);

    int Key();
    Wartosc Content();

};


#endif //LAB8_TREENODE_HH
