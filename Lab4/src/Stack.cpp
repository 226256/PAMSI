#include "Stack.hh"



//----------konstruktory,destruktory i inne traktory---------
Stack::Stack(){
    this->first=NULL;
    this->amount=0;
}



Stack::~Stack(){
    Node* temp;
    while(this->first!=NULL){
        temp=this->first->getNext();
        delete this->first;
        this->first=temp;
    }
    this->amount=0;
}
//------------------------------------------------------------



//metoda objektow typu Stack zwracajaca rozmiar kazdego stosu
//nic tu sie nie dzieje wiec co bedziemy sie rozwijac na tematy nikogo nie obchodzace
unsigned int Stack::size(){
    return this->amount;
}



//wpychamy element na stos, kupa sie spietrza wiec juz nie widac co bylo na dnie
bool Stack::push(Node* element){
    //mamy 2 opcje, albo stos jest pusty albo cos juz tam jest
    // no i zastrzegam ze do stosu mozna wlozyc tylko i wlyacznie wezel ktory na nic nie wskazuje!!!

    if(this->amount!=0 && element->getNext()==NULL){
        element->setNext(this->first->getNext());   //biore wskaznik pierwszy element w stosie i wkladam go do naszego nowego elementu
        this->first=element;              //no a pierwszym elementem stosu jest teraz nowiutki czysciutki elemencik
        this->amount++;                             //no jeszcze trzeba dodac info o nowym elemencie, tzn ze teraz kupa sie rozrosla i jest o 1 wiecej reczy w niej
//        std::cout << "Element pushed" << std::endl;         //a napisze sobie zeby wiedziec ze dziala i nie wywala sie albo ze robi to czego chce xddd
        element=NULL;
        return true;
    }
    else if(this->amount==0 && element->getNext()==NULL){       //tutaj prosta sprawa, dodam sobie zeby odrozniac czy faktycznie dodalem pierwszys element i stos robi co chce
        this->first=element;        //wskaznik na pierwszy element to od teraz jest wskaznik na nowy
        this->amount++;             //trzeba zwiekszyc ilosc elementow w stosie
//        std::cout << "First element added" << std::endl;        //specjalnie inne zeby widziec ze to PIERWSZY :D nobody expected the spanish incvisition xdd
        element=NULL;
        return true;
    }
    else{
        //nie wiem jakim cudem cos mogloby pojsc nie tak xdd
        //tylko gdyby ktos chcial wrzucic wezel ktory wskazuje na cos xdd
        std::cerr << "Something went wrong :(" << std::endl;                //no to juz trzeba miec pecha, albo korzystac z windowsa... choc to jedno i to samo
        return false;
    }
}


//prosta sprawa, zdejmujemy obiekt ze stosu jak gacie ze sterty brudnych ubran kolo lozka,
//dzieki temu mozemy sie dobrac do czystych ktore leza na samym dnie
//wiec ze schematu kupy brudnych ubran trzeba wykreslic to ze leza tam brudne gacie nr1
Node* Stack::pop(){
    Node* temp;                 //tworze sobie wskaznik ktory zwroce uzytkownikowi, to taki chwytak bo brudne majtki na stercie mogly juz lezec kilka dni
    if(this->amount!=0){
        temp=this->first;           //no i przejmuje od stosu chwytakiem pierwszy element
        this->first=temp->getNext();        //jako nowy poczatkowy ustawiam ten z ktorym stycznosc mial poprzedni pierwszy
        temp->setNext(NULL);                //zeby moje brudne gacie nie mialy nic wspolnego z tymi lezacymi na szczycie kupy, zrywam wiazanie pomiedzy nimi
        this->amount--;                     //no i w swoim indeksie zapisuje ze na stosie lezy 1 mniej element
        return temp;                        //no i trzymajac gacie chwytakiem oddaje je uzytkownikowi(np dziewczynie zeby gacie wyprala)
    }
    else{
        //standardowo zawsze musi sie znalezc ktos kto zepsuje impreze :P
        std::cerr << "There is nothing in the stack" << std::endl;
        return NULL;
    }
}



//tutaj trzeba napisac cala funkcje przeszukujaca stos w poszukiwaniu danego elementu
//zakladamy ze zawsze znajdzie kiedys tam szukany element bo gdyby nie to nie moznaby takiego czasu zaliczyc do sredniej
void Stack::do_algorithm(const int v,Node** temp){
    int w=v;

unsigned int k=0;
    unsigned int s=this->size();
    for(unsigned int i=1;i<s;i++) {
        temp[i] = this->pop();
        if(temp[i]->getElem()==w){
            k=i;
            break;
        }
    }

    if(temp[k]==NULL) std::cerr << "Didnt find a value" << std::endl;
    else if(temp[k]->getElem()==w) std::cout << "Element found!" << std::endl;
}