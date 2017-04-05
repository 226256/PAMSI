#ifndef INODE_HH
#define INODE_HH

#include <iostream>

//w tym naglowku deklarujemy ile razy chcemy powtarzac czynnosc liczenia czasu
const unsigned int rep=10;

//no to stworzymy jescze tablice globalna ktora bedzie nam przechowywac rozmiar problemow czyli ilosc elementow ktore musimy przeszukac
const unsigned int size_of_problem[5]={10,100,1000,10000,100000};


//tutaj sobie zadeklarujemy jakiego elementu bedziemy szukac, w main dodamy sobie tyle wezlow ile jest w size_of_problem wszystkie wyzerujemy a na koncu ustawimy 1
const int seeked=1;


class Node{
    int element;
    Node* next;
//    Node* prev;
public:
    //---konstruktory dla wezla do roznego uzytku
    Node():element(0),next(NULL)/*,prev(NULL)*/{std::cout<<"To ja konstruktor sie nazywam!" << std::endl;} //tworzy wezel pusty
    Node(Node* N);     //tworzy wezel z sama wartoscia do niczego nie przyporzadkowany
    Node(const int& value,Node* N);     //tworzy wezel do listy jednokierunkowej
//    Node(const int& value, Node* N/*, Node* P*/);       //tworzy wezel do listy dwukierunkowej


    ~Node();

    Node* getNext();    //metoda do uzyskania nastepnego wezla kiedy mamy poprzedni
//    Node* getPrev();    //metoda do uzyskania poprzedniego wezla w sekwencji
    int getElem();      //zwraca element z danego wezla
    void setNext(Node* N);  //ustawia w wezle wskaznik na nastepny
//    void setPrev(Node* P);  //ustawia w wezle wskaznik na poprzedni
    void setElem(int&);     //Ustawia w wezle wartosc elementu
};

#endif