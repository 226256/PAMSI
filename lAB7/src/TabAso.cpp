//
// Created by maciek on 27.04.17.
//

#include "../inc/TabAso.hh"

/* konstruktory, destruktor oraz funkcje zwracajace podstawowe informacje */
TabAso::TabAso() {
    this->rozmiar=0;
    this->wolnemiejsca=0;
    this->tablica= nullptr;
}

TabAso::TabAso(int rozm) {
    this->rozmiar=rozm;
    Para** temp=new Para*[rozm];
    this->tablica=temp;
    this->wolnemiejsca=rozm;
}


TabAso::~TabAso() {
    delete[] this->tablica;
    this->tablica= nullptr;
    this->rozmiar=0;
    this->wolnemiejsca=0;
}

int TabAso::rozm() {
    return this->rozmiar;
}

int TabAso::ilewolnych() {
    return this->wolnemiejsca;
}

/*-------------------------------------------------------------------------*/

/*wyszukiwanie elementu za pomoca jawnej funkcji search
 *
 * Parametry:
 *  -klucz w postaci stringa
 *
 * Zwraca:
 *  -wskaznik do elementu o kluczu podanym jako parametr jesli znaleziony
 *  -wskaznik pusty(nullptr) jesli nie znaleziony
 *  -rzuca wyjatek jesli poszukiwania na pustej tablicy
 *
 */
Para* TabAso::search(std::string key) {
    if(this->rozmiar==0) { throw PustaTablica(); }
    int hasz=h(key);
    for(int i=hasz;i<rozmiar;++i) {
        if (tablica[i] != nullptr) {
            if (tablica[i]->WezKlucz_str() == key) return tablica[i];
        }
    }
    for(int i=0;i<hasz;++i){
        if(tablica[i]!= nullptr) {
            if (tablica[i]->WezKlucz_str() == key) return tablica[i];
        }
    }
    return nullptr;
}



/* Pobranie elementu z komorki o kluczu key, najpierw wywolanie funkcji search a nastepnie wyluskanie elementu
 * Przeciazenie operatora indeksowania []
 *
 * Parametry:
 *  -klucz w postaci string
 *
 * Zwraca:
 *  -referencje do stalego elementu pobranego z Para, czyli zwraca wartosc
 *  -jako ze uzywa sie funkcji search, rzuca wyjatek pustej tablicy jesli pusta
 *  -rzuca wyjatek braku elemenetu o danym kluczu
 *
 */
const int TabAso::operator[](std::string key) {
    Para* temp=this->search(key);
    if(temp != nullptr){
        return temp->WezWar();
    }
    else{
        throw BrakElementu();
    }
}



/*
 * Dodanie elementu do tablicy(nie przewiduje powiekszania tablicy w trakcie dodawania elementow do pelnej tablicy)
 *
 * Parametry:
 *  -klucz(string) ktory funkcja haszujaca zamieniamy na inta a nastepnie znajdujemy mu miejsce w tablicy
 *  -wartosc jaka zostaje przyporzadkowana danemu kluczowi
 *
 * Zwraca:
 *  -void
 *
 */
void TabAso::put(std::string Key, Wartosc war,Wariant hasz) {
    int i = 0;
    if(hasz==pierwszy){
        i=this->h(Key);
    }
    else if(hasz==drugi){
        i=this->h2(Key);
    }
    //pomocnicza zmienna zeby pamietac stworzony klucz
    int k=i;
    if(this->wolnemiejsca != 0){
        while(tablica[i] != nullptr && i != this->rozmiar-1){
            ++i;
        }
        if(tablica[i] == nullptr){
            Para* temp=new Para(Key,war);
            tablica[i]=temp;
            this->wolnemiejsca--;
        }
        else{
            int j=0;
            while(tablica[j] != nullptr && j != k){
                ++j;
            }
            if(tablica[j] == nullptr){
                Para* temp=new Para(Key,war);
                tablica[j]=temp;
                this->wolnemiejsca--;
            }
        }
    }
    else{
        throw BrakMiejsca();
    }
}




/*
 * Funkcja haszujaca klucz (w przyszlosci mozna dodac opcje wyboru sposobu haszowania
 *
 * Parametry:
 *  -klucz w postaci string
 *
 * Zwraca:
 *  -klucz w postaci int
 *
 */
int TabAso::h(std::string& Key) {
    //funkcja haszujaca klucz
    int pierwsza=Key[0];
    int druga,trzecia;
    int klucz;
    klucz=pierwsza;
    if(Key.length()==2){
        druga=Key[1];
        klucz=pierwsza+druga;
    }
    if(Key.length()>2){
        druga=Key[1];
        trzecia=Key[2];
        klucz=pierwsza+druga+trzecia;
    }

    //haszowanie modularne
    return klucz % this->rozmiar;
}

int TabAso::h2(std::string &) {
    int i=0;


    return i;
}

//metody ktore wykorzystam do testowania metody search, moga sie nie przydac nigdzie indziej
void TabAso::zbuduj(std::string szukane,int wartosc,Wariant hasz) {
    this->put(szukane,wartosc,hasz);
    for(int i=0;this->wolnemiejsca>0;++i){
        //TODO zbudowac tablice z randomowych stringow ale tak zeby sie nie powtarzaly
        std::string tmp;
        sprintf((char*)tmp.c_str(),"%d",i);
        this->put(tmp.c_str(),i,hasz);
    }
}

void TabAso::zadanie(std::string szukane) {
    Para* temp=this->search(szukane);
    if(temp== nullptr){
        std::cerr << "Nie znaleziono" << std::endl;
    }
}