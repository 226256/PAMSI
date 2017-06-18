//
// Created by maciek on 18.05.17.
//

#include "../inc/TreeNode.hh"


//--------------- Konstruktory i destruktory -----------------
TreeNode::TreeNode() {
    this->LewySyn= nullptr;
    this->PrawySyn= nullptr;
    this->przodek= nullptr;
    this->dane=0;
    this->klucz=0;
}

TreeNode::TreeNode(int & Key, Wartosc & Data) {
    this->LewySyn= nullptr;
    this->PrawySyn= nullptr;
    this->przodek= nullptr;
    this->klucz=Key;
    this->dane=Data;
}

TreeNode::~TreeNode() {
    this->LewySyn= nullptr;
    this->PrawySyn= nullptr;
    this->przodek= nullptr;
    this->klucz=0;
    this->dane=0;
}
//-------------------------------------------------------------


TreeNode* TreeNode::Ancestor() {
    return this->przodek;
}

TreeNode* TreeNode::LeftSon() {
    return this->LewySyn;
}

TreeNode* TreeNode::RightSon() {
    return this->PrawySyn;
}
Wartosc TreeNode::Content() {
    return this->dane;
}
int TreeNode::Key() {
    return this->klucz;
}

void TreeNode::setAncestor(TreeNode *Arg) {
    this->przodek=Arg;
}

void TreeNode::setLeftSon(TreeNode *Arg) {
    this->LewySyn=Arg;
}

void TreeNode::setRightSon(TreeNode *Arg) {
    this->PrawySyn=Arg;
}