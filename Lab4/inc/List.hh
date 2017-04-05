#ifndef LIST_HH
#define LIST_HH

#include "iList.hh"
#include "Node.hh"

class List : public virtual iList{
    Node* head;
    unsigned int amount;

public:
    List();
    ~List();

    bool add(unsigned int& position,int value);  //wstawia wezel z elementem o wartosci value, na pozycje nr position
    bool rm(unsigned int& position);                //usuwa wezel nr position z listy
    Node* get(unsigned int& postition);         //zwraca wskaznik na wezel nr position w liscie
    unsigned int size();                        //zwraca rozmiar listy
    Node* find(int& identificator);             //zwraca wskaznik na pierwszy wezel w liscie na ktory natrafi i znajdujje sie tam element o warotsic identificator

    void do_algorithm(const int);
};

#endif