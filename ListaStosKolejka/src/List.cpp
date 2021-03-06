#include "List.hh"


//------------------konstruktor i destruktor-------------

//nie wiem czy sie przyda ale na wszelki wpyadek tworze konstruktor bezparametryczny, nie zaszkodzi a moze pomoc :D
List::List(){
    head=NULL;
    amount=0;
    std::cout << "List exists" << std::endl;
}



//destruktor, musi zniszczyc wszystkie elementy w liscie
List::~List(){
    Node* temp;
    for(unsigned int i=1;i<this->amount;i++){
        temp=this->head->getNext();
        head->~Node();
        head=temp;
    }

    //na koncu zostanie tylko 1 element i jego tez trzeba zniszyc
    delete head;
    amount=0;
    std::cout << "List destructed" << std::endl;
}

//----------------------------------------------------------




//metoda zwracajaca wskaznik do wezla na pozycji "position"
//numerowanie wezlow od 1, pozycje 0 uznajemy za glowe, a postion+1 za ogon(dla listy dwukierunkowej

//zwraca wskaznik na potrzebny wezel albo NULL w przypadku przekroczenia zakresu listy
Node* List::get(unsigned int& position){

    if(position > this->amount){
        //jesli przypadkiem ktos calkowicie nieodpowiedzialny poda nr pozycji
        // a takiej pozycji nie bedzie to taki klamczuszek dostanie odpowiednia informacje zwrotna
        std::cerr << "Wrong position, higher than amount of elements in list" << std::endl;
        return NULL;    //No i cos trzeba zwrocic to dostanie fige czyli NULL
    }
    else{
        Node* temp=this->head;  //bierzemy sobie wskazniczek na pierwszy element
        for(unsigned int i=1;i<position;i++){//a potem idziemy tyle razy ile trzeba
            temp=temp->getNext(); //za kazdym razem nasz wskaznik na element zamieniamy na wskaznik na nastepny
        }
        return temp;
    }

}

//metoda dodajaca nowy wezel do listy, na danej pozycji
bool List::add(unsigned int &position,int value){
    //na samym poczatku musimy wyjac z lsty pozycje wezla za ktorym chcemy wstawic nowy
    //a potem do niego wstawiamy wskaznik na nowy a do nowego wskaznik na jeszcze nastepny
    //jesli ostatni to NULL
    unsigned int firstindex=1;
    if(position <= this->amount && position != firstindex && this->amount!=0) {
//        std::cout << "probujemy dodawac w srodku" << std::endl;
        unsigned int tempor=position-1;
        Node* prevNew=this->get(tempor);        //robie tymczasowy wskaznik na element przed miejscem gdzie chce wstawic nowy wezel
        Node* nextNew=this->get(position);      //oraz na ten ktory przesune a na jego miejsce wstawie nowy wezel

        Node* temp=new Node(value,nextNew);     //tworze wskaznik na nowy wezel, w konstruktorze wezla od razu wrzucam wwskaznik do elementu na ktory bedzie wskazywac
        prevNew->setNext(temp);                 //no i do tego poprzedniego wskaznik na nowy wezel

        this->amount++; //wiadomo trzeba jeszcze zwiekszyc rozmiar listy
        return true;
    }
    else if(position==(this->amount+1) && this->amount!=0){
//        std::cout << "probujemy dodawac na koncu" << std::endl;
        unsigned int tempor=this->amount-1;
        Node* prelast=this->get(tempor); //dodaje na koncu listy wiec nie mam wskaznika na ostatni element listy musze go uzyskac

        Node* temp=new Node(value,NULL);     //tworze wskaznik na nowy wezel, w konstruktorze wezla od razu wrzucam wwskaznik do elementu na ktory bedzie wskazywac
        prelast->setNext(temp);                 //no i do tego poprzedniego wskaznik na nowy wezel

        this->amount++; //wiadomo trzeba jeszcze zwiekszyc rozmiar listy
        return true;
    }
    else if(this->amount==0 || position==firstindex){
//        std::cout << "pbobujemy dodawac pierwszy element" << std::endl;
        /*
         * jesli lista jest pusta albo wrzucam na pierwsze mijsce to pierwszy sposob nie przejdzie
         * bo musimy pobrac wskaznik na poprzedni element a jesli jest pusta lista to to nie przejdzie,
         * jesli pierwsze miejsce na liscie to nie pobierzemy ostatniego elementu :(((((
         * wiec trzeba sie "pobawic glowa" xdd
         */
        Node* temp=this->head;          //robie tymczasowy wsk na to co wskazywala glowa(jesli lista pusta to NULL
        Node* newNode=new Node(value,temp);   //no i tworze nowy element, ktory od poczatku bedzie wskazywal na to na co glowa w tym momencie

        this->head=newNode;     //no i do glowy wrzucamy wskaznik na nasz nowy wezel

        amount++; //jeszcze zwiekszamy szybciutko rozmiar listy

        //no i wszystko cacy <3
        return true;
    }
    else{
        //tutaj jeszcze wyjatkowy przypadek jak jakis bezmozg poda index niepasujacy do zadnych kryteriow... YOLO!
        std::cerr << "Position out of list!" << std::endl;
        return false;
    }
}


//no i bierzemy na warsztat funkcje usuwajaca wezel z pozycji nr position
bool List::rm(unsigned int& position){
    /*
     * bede potzrebowal zapisac sobie gdzies blisko wskazniki na element poprzedzajacy i nastepujacy usuwanego
     * zeby zapisac od razu do poprzedzajacego adres nastepujacego i bez krepacji uzyc destruktora mojego wezla
     * jesli usuwamy pierwszy element listy to bierzemy tylko nastepujacy!
     */
    unsigned int firstelem=1;
    if(position==firstelem){
        unsigned int temp = position+1;
        Node* nextRm=this->get(temp);
        this->head->~Node();
        this->head=nextRm;
        this->amount--;

        //dziekuje dobranoc
        return true;
    }
    else if(position != 0 && position <= this->amount){
        unsigned int temp=position-1;
        Node* prevRemove=this->get(temp);
        temp=position+1;
        Node* nextRemove=this->get(temp);
        Node* removed=prevRemove->getNext();
        removed->~Node();
        prevRemove->setNext(nextRemove);
        this->amount--;

        //system rozwalony
        return true;
    }
    else{
        //jesli jakis ciamciak poda zly index, tzn mniejszy od 1 albo wiekszy od rozmiaru to dostaje wp....
        std::cerr << "Wrong index, no node to remove" << std::endl;
        return false;
    }
}



//nudna funkcja ktora kazdemu odpowie "dzien dobry" i powie ile elementow liczy lista
unsigned int List::size(){
    return this->amount;
}


//oczywiscie poda mi namiary na pierwszego znalezionego po co bedzie szukac dalej
Node* List::find(int& identifier){
    Node *temp = this->head;      //no to tak, towrzymy sobie wskaznik na element typu wezel
    if(temp!=NULL && temp->getElem()!=identifier){
        for(unsigned int i=1;i<=this->amount;i++){
            temp=temp->getNext();
            if(temp==NULL) break;
            if(temp->getElem()==identifier) break;
        }
    }
    return temp;
}




void List::do_algorithm(const int w){
    int v=w;
    Node* temp=find(v);
    if(temp==NULL)std::cerr << "Didn't find" << std::endl;
    else std::cout << temp <<std::endl;
}