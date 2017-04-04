#ifndef STACK_HH
#define STACK_HH

#include "iStack.hh"
#include "Node.hh"

/*
 * No to tak klasa stos to pozwala nam na wiele przydatnych rzeczy
 * np mozemy sobie wrzucac elementy jak do beczki i nie widziec co jest na samym dnie
 * a musimy miec najpierw taki element we wlasnych raczkach zeby go tam wrzucic
 * wiec nasza klasa nie tworzy sama nowych tylko dorzuca te ktore dostanie od uzytkownika
 * no i zwraca tylko wskaznik na element a co potem uzytkownik zrobi z tym wskaznikiem to juz jego sprawa
 *
 */


class Stack : public iStack{
    Node* first;
    unsigned int amount;

public:
    Stack();
    ~Stack();

    virtual unsigned int size();        //metoda size() zwraca rozmiar stosu, czyli ilosc elementow w srodku
    virtual Node* pop();                //metoda pop() wyciaga element ze stosu czyli ustawia first na nastepny w stosie a wskaznik na ten sciagany zwraca
    virtual bool push(Node* element);   //metoda push() dodaje do stosu nowy element czyli ustawia first na ten nowy element a stary first wklada do wezla,zwraca true
                                        //zwraca true jesli sie udalo


};

#endif