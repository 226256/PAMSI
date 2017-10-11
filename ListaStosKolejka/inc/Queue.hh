#ifndef QUEUE_HH
#define QUEUE_HH

#include "iQueue.hh"
#include "Node.hh"

class Queue: public iQueue{
    Node* first;
    Node* last;
    unsigned int amount;

public:
    Queue();
    ~Queue();

    unsigned int size();                //metoda zwracajaca rozmiar kolejki
    bool enqueue(Node* element);        //metoda dodajaca wezel do kolejki na sam koniec(wezel podany przez uzytkownika, ktory na nic nie wskazuje, moze miec tylko element
    Node* dequeue();                     //metoda zabierajaca pierwszy element z kolejki(czyli ten ktory zostal dodany do kolejki przed wszystkimi innymi)

    void do_algorithm(const int);
};

#endif