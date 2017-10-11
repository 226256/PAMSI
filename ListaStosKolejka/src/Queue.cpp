#include "Queue.hh"

//---------konstruktory i destruktory-----------

Queue::Queue(){
    this->first=NULL;
    this->last=NULL;
    this->amount=0;
    std::cout << "We made a queue" << std::endl;
}


Queue::~Queue(){
    Node* temp;
    while(this->first!=NULL){
        temp=this->first;
        this->first=temp->getNext();
        temp->~Node();
    }
    this->last=NULL;
    this->amount=0;
std::cout << "We removed a Queue" << std::endl;
}

//-----------------------------------------------


//metoda zwracajaca rozmiar kolejkki, prosta sprawa
unsigned int Queue::size(){
    return this->amount;
}


/*
 * metoda dolaczajaca wezel do konca kolejki wiec wskaznik first sie nie zmienia(chyba ze wrzucmy pierwszy element)
 * zmieniamy tlyko i wylacznie element last
 * do tego beda nam potrzbne wskazniki na poprzedni i nastepny element w kolejce
 */
bool Queue::enqueue(Node* element){
    //Po pierwsze musimy miec wskaznik na ostatni element zeby dolaczyc do niego nowy
    //to tak jakby byla kolejka po chleb za PRLu no i kazdy w kolejce wie kto jest przed nim i za nim
    //zeby mozna bylo w ostatnim momencie powiedziec "ale pan tu nie stal!"

    //tutaj uproszczenie dla opcji ze w kolejce jeszcze nikt nie stoi, widac ma cynk ze jutro na sklep rzuca cos dobrego i ustawia sie o 4 rano(dnia poprzedniego)
    if(this->amount==0 && element->getNext()==NULL ){
        if(this->first!=NULL || this->last!=NULL){      //tak sobie pomyslalem ze skoro kompilator nie sprawdza poprawnosci wskaznikow to moglem popelnic gdzies blad
            //no i jakby sie okazalo ze w pustej kolejce uchwyt na pierwszy i ostatni element to nie to samo czyli NULL
            //to cos nie bangla i trzeba wywalic blad i generalnie wszystko po kolei: segmentation fault, BSoD, opisac we wiadomosciach o 19.30 itd itp
            std::cerr << "Problem with Queue, its empty but first and last are pointers no equal NULL" << std::endl;
            return false;
        }
        this->first=element;        //no ale jak juz wszystko jest dobrze to wkladam do wskaznika na pierwszy element adres mojego nowego elementu
        this->last=element;         //no i skoro jest pierwszy a nikogo wiecej nie ma to jest tez ostatni(dodatkowo nie ma nikogo wokol niego
        this->amount++;             //no a gosciu ktory liczy sobie klientow w kolejce zapisuje ze jest juz o 1 wiecej
        std::cout << "Queue begins" << std::endl;
        return true;
    }

        //tutaj bedzie wyszla szkola jazdy, ktos juz stoi w kolejce wiec bedzie walka o przetrwanie
        //na sam poczatek musze wiedziec kto jest wokol mnie wiec warto by sobie zapisac ich adresy
        //na wypadek gdyby ktos sie probowal wepchac to sprawdzimy adres takiego delikwenta i uzywamy magicznych, pradawnych slow:
        /* ALE PAN TU NIE STAL */
        //przyjezdzaja bagiety i zabieraja delikwenta
    else if(this->amount > 0 && element->getNext()==NULL){
        this->last->setNext(element);
        this->last=element;
        this->amount++;
//        std::cout << "New node added to queue" << std::endl;
        return true;
    }

    else{   //standardowo juz, trzeba pokazac ze nie jestes nieomylny i moze sie zdarzyc ze cos pojdzie nie tak wiec musi byc furtka
        std::cerr << "Something went wrong during enqueing" << std::endl;
        return false;
    }



}

/*
 * metoda zabierajaca z kolejki pierwszy element(czyli ten ktory pierwszy do niej stanal, za nim dostawialy sie nowe elementy)
 * wiec zabierajac pierwszy element zabieram wskaznik na niego a ustawiam jako first wskaznik na nastepny po nim, czyli delikwent musi wiedziec kto za nim stal
 * zeby powiedziec first kto teraz bedzie pierwszy
 *
 */
Node* Queue::dequeue(){
    //rozne akcje kiedy w kolejce nie ma elementow, jest ostatni element lub jest wiecej niz 1 element

    Node* temp;         //wskaznik ktory bede zwracal za kazdym razem
    if(this->amount==1){
        temp=this->first;               //wstawiam do tempa wskaznik na pierwszy element
        temp->setNext(NULL);            //zeby nie wskazywal na nic ten ktorego wyciagam, bo w koncu juz go to nei obchodzi(na wszelki wypadek tutaj)
        this->first=NULL;               //teraz nie ma nic w kolejce wiec trzeba od razu zapisac ze pierwszym elementem nie jest nic czyli wskaznik na NULL
        this->last=NULL;                //no i ostatni to to samo co pierwszy czyli tez NULL
        this->amount--;                 //no i gosciu pilnujacy kolejki musi zapisac ze jeden element zwial
        return temp;
    }
    else if(this->amount > 1){
        temp=this->first;               //wkladam do tempa wskaznik na pierwszy element kolejki
        this->first=temp->getNext();    //teraz drugi element bedzie pierwsztym wiec wybieram z tego bylego pierwszego wskaznik na nastepny i mowie gosciowi od kolejki
        //ze to tearz ten nastepny jest pierwszy
        temp->setNext(NULL);            //tego ktorego zabieram z kolejki juz nie obchodzi kto za nim stal
        this->amount--;                 //no i gosciu od kolejki musi zapisac ze kogos w kolejce juz brakuje, jego kolej na lopatke bez kosci w miesnym
        return temp;
    }
    else{//tutaj wpada przypadek gdy nie ma nikogo w kolejce albo cos czego ja nie wymyslilem
        std::cerr << "There is nothing in the queue or something went wrong" << std::endl;
        return NULL;
    }


}

//tutaj trzeba opisac funkcje przszukujaca kolejke w poszukiwaniu elementu
//czyli tak zabieramy z poczatku i dodajemy na koniec az nie natrafimy na szukany element

void Queue::do_algorithm(const int v){
    int w=v;
    Node* temp=this->dequeue();
    while(temp->getElem()!=w || temp!=NULL){
        temp=this->dequeue();
        this->enqueue(temp);
        if(temp->getElem()==w || temp==NULL) break;
    }

    if(temp==NULL) std::cerr<<"Didnt find your element" << std::endl;
    else if(temp->getElem()==w) std::cout << "element found" << std::endl;
}


