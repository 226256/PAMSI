#include "List.hh"

//metoda zwracajaca wskaznik do wezla na pozycji "position"
//numerowanie wezlow od 1, pozycje 0 uznajemy za glowe, a postion+1 za ogon(dla listy dwukierunkowej

//zwraca wskaznik na potrzebny wezel albo NULL w przypadku przekroczenia zakresu listy
Node* List::get(unsigned int& position){

    if(position > this->amount){
        std::cerr << "Wrong position, higher than amount of element in list" << std::endl;
        return NULL;
    }
    else{
        Node* temp=this->head;
        for(unsigned int i=0;i<position;i++){
            temp=temp->getNext();
        }
        return temp;
    }

}

//metoda dodajaca nowy wezel do listy, na danej pozycji
bool List::add(unsigned int &position){
    //na samym poczatku musimy wyjac z lsty pozycje wezla za ktorym chcemy wstawic nowy
    //a potem do niego wstawiamy wskaznik na nowy a do nowego wskaznik na jeszcze nastepny
    //jesli ostatni to NULL



    Node* temp=new Node()


    return good;
}

bool List::rm(int& position){
    bool good=true;

    return good;
}


unsigned int List::size(){

}