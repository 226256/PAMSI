#include "Node.hh"

/*
 * tutaj zbior podstawowych metod
 * z ktorych mozna korzystac przy pracy na wezlach
 * np podczas dodawania nowego wezla do listy itp itd
 */


Node::Node(Node* N){
    this->element=0;
    this->next=N;
    //this->prev=NULL;
}

Node::Node(const int& val,Node* N){
    this->element=val;
    this->next=N;
    //this->prev=NULL;

}
/*
Node::Node(const int& val,Node* N,Node* P){
    this->element=val;
    this->next=N;
    this->prev=P;

}*/

Node::~Node(){
    this->next=NULL;
  //  this->prev=NULL;
}

Node* Node::getNext(){
    return next;
}

/*
Node* Node::getPrev(){
    return prev;
}*/

int Node::getElem(){
    return element;
}

void Node::setNext(Node* N){
    Node* temp=N;
    this->next=temp;

}
/*
void Node::setPrev(Node* P){
    Node* temp=P;
    this->prev=temp;
}*/

void Node::setElem(int& v){
    this->element=v;
}