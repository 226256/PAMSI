//
// Created by maciek on 27.04.17.
//

#include "../inc/TabAso.hh"


TabAso::TabAso() {
    this->rozmiar=0;
    this->tablica= nullptr;
}

TabAso::~TabAso() {
    delete[] this->tablica;
    this->tablica= nullptr;
    this->rozmiar=0;
}

int TabAso::rozm() {
    return this->rozmiar;
}

const int& TabAso::operator[](std::string key) const {
//TODO mozliwosc pobierania elementu na miejscu z kluczem key



}

void TabAso::put(std::string Key, Wartosc war) {


}

void TabAso::h(std::string& Key) {
    //funkcja haszujaca klucz
    int pierwsza=Key[0];
    int druga,trzecia;
    if(Key.length()>1){
        druga=Key[1];
    }
    if(Key.length()>2){
        trzecia=Key[2];
    }

}