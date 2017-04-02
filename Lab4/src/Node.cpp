#include "Node.hh"


Node::Node(const int& val){
    this->element=val;
    this->next=NULL;
    this->prev=NULL;
}

Node::Node(const int& val,Node* N){
    this->element=val;
    this->next=N;
    this->prev=NULL;

}

Node::Node(const int& val,Node* N,Node* P){
    this->element=val;
    this->next=N;
    this->prev=P;

}

Node::~Node(){
    this->next=NULL;
    this->prev=NULL;
}

Node* Node::getNext(){
    return next;
}

Node* Node::getPrev(){
    return prev;
}

int Node::getElem(){
    return element;
}

void Node::setNext(Node* N){
    this->next=N;
}

void Node::setPrev(Node* P){
    this->prev=P;
}