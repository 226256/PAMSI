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
    for(int i=0;i<rozm;++i){
        this->tablica[i]= nullptr;
    }
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
const int TabAso::operator[](std::string key){
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
 *  -rzuca wyjatek BrakMiejsca jesli dodajemy do pelnej tablicy
 *
 */
void TabAso::put(std::string Key, Wartosc war,Wariant hasz) {
    int i = 0;
    if(hasz==haszpierwszy){
        i=this->h(Key);
    }
    else if(hasz==haszdrugi){
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
            else{throw NieZnalezionoMiejsca();}
        }
    }
    else{
        throw BrakMiejsca();
    }
}


/*
 * Metoda tworzaca mi klucz typu int z klucza typu string
 *
 * Parametry:
 * -klucz w postaci string
 *
 * Zwraca:
 * -klucz w postaci int
 *
 */

int TabAso::zamianaklucza(std::string &Key) {
    //funkcja haszujaca klucz
    int pierwsza=Key[0];
    int druga,trzecia,czwarta,piata;
    int klucz;
    klucz=pierwsza;
    if(Key.length()==2){
        druga=Key[1];
        klucz=pierwsza+druga;
    }
    if(Key.length()==3){
        druga=Key[1];
        trzecia=Key[2];
        klucz=pierwsza+druga+trzecia;
    }
    if(Key.length()==4){
        druga=Key[1];
        trzecia=Key[2];
        czwarta=Key[3];
        klucz=pierwsza+druga+trzecia+czwarta;
    }
    if(Key.length()>4){
        druga=Key[1];
        trzecia=Key[2];
        czwarta=Key[3];
        piata=Key[4];
        klucz=pierwsza+druga+trzecia+czwarta+piata;
    }
    return klucz;
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
    int klucz=this->zamianaklucza(Key);
    //haszowanie modularne
    return klucz % this->rozmiar;
}

int TabAso::h2(std::string &Key) {
    int klucz=this->zamianaklucza(Key);
    //haszowanie przez mnozenie
    /*
     * za rada Knutha bierzemy A=s/2^i gdzie i=15 a s = 2^5
     */
    float A=0.226256;
    //potrzebuje uzyskac czesc ulamkowa z mnozenia
    float temp=klucz*A;
    int temp1=(int)temp;
    temp-=temp1;

    return this->rozmiar*temp;
}

//metody ktore wykorzystam do testowania metody search, moga sie nie przydac nigdzie indziej




/*
 * Metoda budujaca mi tablice z kluczy ktore sa najjwzyczajniej numerkami
 * bo nie chcialo mi sie kombinowac randomowych slow
 */
void TabAso::zbuduj(std::string szukane,int wartosc,Wariant hasz) {

    this->put(szukane,wartosc,hasz);

    for(int i=0;this->wolnemiejsca>0;++i){
//        std::cout << "moj klucz " << tmp << std::endl;

        //TODO zbudowac tablice z randomowych stringow ale tak zeby sie nie powtarzaly
//------------------------------------------------------
//przypadek pesymistyczny
//        std::string tmp;
//        sprintf((char*)tmp.c_str(),"%d",i);
//        this->put(tmp.c_str(),i,hasz);
//------------------------------------------
        //przypadek optymistyczny
        std::string tmp="optymistyczny";
	 this->put(tmp,i,hasz);
// ------------------------------------------------------
	if(this->rozmiar>100000)std::cout << this->wolnemiejsca << std::endl;
    }
}

void TabAso::zadanie(std::string szukane) {
    Para* temp=this->search(szukane);
    if(temp== nullptr){//tak na wszelki wypadek zebym wiedzial czy cos nie gra
        std::cerr << "Nie znaleziono" << std::endl;
    }
    else std::cout << temp->WezWar() << std::endl;
}

void TabAso::reset() {
    delete[] this->tablica;
    int rozm=this->rozmiar;
    Para** temp=new Para*[rozm];
    this->tablica=temp;
    this->wolnemiejsca=this->rozmiar;
}
