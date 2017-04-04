#include "Stack.hh"



//----------konstruktory,destruktory i inne traktory---------
Stack::Stack(){
    this->first=NULL;
    this->amount=0;
}



Stack::~Stack(){
    Node* temp;
    for(unsigned int i=1;i<this->amount;i++){
        temp=this->first->getNext();
        this->first->~Node();
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
        std::cout << "Element pushed" << std::endl;         //a napisze sobie zeby wiedziec ze dziala i nie wywala sie albo ze robi to czego chce xddd
        return true;
    }
    else if(this->amount==0 && element->getNext()==NULL){       //tutaj prosta sprawa, dodam sobie zeby odrozniac czy faktycznie dodalem pierwszys element i stos robi co chce
        this->first=element;        //wskaznik na pierwszy element to od teraz jest wskaznik na nowy
        this->amount++;             //trzeba zwiekszyc ilosc elementow w stosie
        std::cout << "First element added" << std::endl;        //specjalnie inne zeby widziec ze to PIERWSZY :D nobody expected the spanish incvisition xdd
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
Node* temp(NULL);

return temp;
}
