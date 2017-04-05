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
    for(unsigned int i=0;i<this->amount;i++){
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
        unsigned int tempor=position-1;
        Node* prevNew=this->get(tempor);        //robie tymczasowy wskaznik na element przed miejscem gdzie chce wstawic nowy wezel
        Node* nextNew=this->get(position);      //oraz na ten ktory przesune a na jego miejsce wstawie nowy wezel

        Node* temp=new Node(value,nextNew);     //tworze wskaznik na nowy wezel, w konstruktorze wezla od razu wrzucam wwskaznik do elementu na ktory bedzie wskazywac
        prevNew->setNext(temp);                 //no i do tego poprzedniego wskaznik na nowy wezel

        this->amount++; //wiadomo trzeba jeszcze zwiekszyc rozmiar listy
        return true;
    }
    if(this->amount==0 || position==firstindex){
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
        Node* nextRm=this->get(temp);       //tutaj tworze sobie wskaznik na element nastepujacy po usuwanym
        this->head->~Node();                //a tutaj robie master of disaster dla elementu wskazywanego przez glowe
        this->head=nextRm;                  //no i glowka teraz juz wie na co ma wskazywac, badz jak glowka!
        this->amount--;                     //biedny amount, lista ma o 1 mniej element wiec on tez obrywa :(

        //dziekuje dobranoc
        return true;
    }
    else if(position != 0 && position <= this->amount){
        unsigned int temp=position-1;
        Node* prevRemove=this->get(temp);       //no tutaj nie wiemy co poprzedza element usuwany wiec musimy to znalezc
        temp=position+1;
        Node* nextRemove=this->get(temp);       //nihil novi sub solar, tak samo bylo wyzej
        Node* removed=prevRemove->getNext();    //no wstawiamy sobie do jakiejs tymczasowej zmiennej wskaznik na nasz element ktoremu zaraz zrobimy aborcje
        removed->~Node();                       //no i jedziemy z frajerem jak Arnold Schwarzenneger w drugim terminatorze!
        prevRemove->setNext(nextRemove);        //wiadomo zamiatamy zabojstwo pod dywan, a poprzedzajacemu usuwanego dajemy wskaznik na nastepujacego
        this->amount--;                         //tylko amount wie o wszystkim i sie sypie tracac na wartosci

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


//oooooo a tutaj bedzie fajny okaz, ta funkcja ma mi szukac ktory wezel posiada to czego szukam
//oczywiscie poda mi namiary na pierwszego znalezionego po co bedzie szukac dalej
Node* List::find(int& identifier){
    Node *temp = this->head;      //no to tak, towrzymy sobie wskaznik na element typu wezel

    if(this->amount != 0) { //najpuierw na wszelki wypadek sprawdzimy czy jest w czym szukac xddd
        do {//wchodzimy do petelki sprawdzajac czy wezel na ktory wskazuje nasz wskaznik ma cos takiego jak identifier
            if (temp->getElem() == identifier) {    //no jesli tak to impreza!!!
                // az do odcinki, czyli break jesli cos takiego sie wydarzy i wyskakujemy z petli
                break;
            } else temp = temp->getNext(); //jesli nie to klinujemy, wrzucamy do naszego tempa, wskaznik nastenego elementu
        } while (temp != NULL); //no i jesli nie bangla to nasz temp zostaje NULL... I rozlega sie smutna muzyka... "Hello darkness my old friend..."
    }

    else{//no jesli nie ma w czym szukac to z pustego i salomon nie naleje wiec elo mordo!
        temp=NULL;
        std::cerr << "There is no nodes in your list!" << std::endl;
    }

    return temp;    //no i wskaznik na wezel z elementem ktorego szukamy wylatuje w swiat, a niedawno jeszcze byl taki maly :'(
}




void List::do_algorithm(const int w){
    int v=w;
    Node* temp=find(v);
    if(temp==NULL)std::cerr << "Didn't find" << std::endl;
}