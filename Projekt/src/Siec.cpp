//
// Created by maciek on 31.05.17.
//

#include "../inc/Siec.hh"

//------------konstrukory i destruktory--------

Siec::Siec() {}

Siec::~Siec() {
    delete[](this->SpisPrzystankow);
}

//--------------------------------------------

/*
 * Metoda poszukujaca najkrotszej sciezki pomiedzy dwoma przystankami
 * Korzysta z algorytmu "A*"
 *
 * Parametry:
 *  -Nazwa przystanku poczatkowego(string)
 *  -Nazwa przystanku koncowego(string)
 *
 * Zwraca:
 *  -Wskaznik do tablicy przechowujacej spis przystankow przez ktore trzeba przejechac
 *  -nullptr jesli nie znaleziono jednego z przystankow podanych jako parametr
 *
 */
Przystanek **Siec::ZnajdzNajkrotszaDroge(std::string Poczatek, std::string Koniec) const {
    //TODO tutaj stowrzyc algorytm wyszukiwania najkrotszej sciezki i zwracania tablicy z przystankami jakie trzeba odwiedzic

    Przystanek** DoPrzejrzenia = new Przystanek* [this->IloscPrzystankow];
    Przystanek** Przejrzane = new Przystanek* [this->IloscPrzystankow];
    std::string Trasa[ROZMIAR];
    int PoczatekID[ROZMIAR] = {0};
    int KoniecID[ROZMIAR] = {0};
    double lat = ZnajdzPrzystanek(Koniec)->getLat;
    double lon = ZnajdzPrzystanek(Koniec)->getLon;
    int i = 0;

//Wczytanie do tablicy wszystkich ID przystankow o nazwie "Poczatek"
    PoczatekID[0] = ZnajdzPrzystanek(Poczatek)->getId();
    bool CzyWszystkie = false;
    while(!CzyWszystkie) {
        Przystanek *temp;
        temp = ZnajdzPrzystanek(Poczatek, PoczatekID);
        if(temp != nullptr) {
            ++i;
            PoczatekID[i] = temp->getId();
        }
        else {
            CzyWszystkie = true;
        }
    }
//Wczytanie do tablicy wszystkich ID przystankow o nazwie "Koniec"
    KoniecID[0] = ZnajdzPrzystanek(Koniec)->getId();
    bool CzyWszystkie = false;
    while(!CzyWszystkie) {
        Przystanek *temp;
        temp = ZnajdzPrzystanek(Koniec, KoniecID);
        if(temp != nullptr) {
            ++i;
            KoniecID[i] = temp->getId();
        }
        else {
            CzyWszystkie = true;
        }
    }

}


/*
 * Metoda wstawiajaca tablice ze wskaznikami do Przystankow(ich spis)
 */
void Siec::setSpisPrzystankow(Przystanek **SpisPrzystankow) {
    Siec::SpisPrzystankow = SpisPrzystankow;
}


/*
 * Metoda ustawiajaca ilosc przystankow w sieci
 */

void Siec::setSpisLinii(Rozklad **SpisLinii) {
    Siec::SpisLinii = SpisLinii;
}

void Siec::setIloscPrzystankow(int IloscPrzystankow) {
    Siec::IloscPrzystankow = IloscPrzystankow;
    this->macierz=new int* [IloscPrzystankow];
    for (int i = 0; i < IloscPrzystankow; ++i) {
        this->macierz[i]=new int [IloscPrzystankow];
    }
}


/*Metoda szukajaca czy w sieci jest przystanek o podanej nazwie
 *
 * Parametry:
 *  -Nazwa przystanku szukanego(string)
 *
 * Zwraca:
 *  -Wskaznik do przystanku jesli znaleziony
 *  -nullptr jesli nie znaleziony
 *
 */
Przystanek *Siec::ZnajdzPrzystanek(std::string Arg) const {
    int i=0;
    bool CzyZnalziony=false;
    while(i<this->IloscPrzystankow && !CzyZnalziony){
        if(this->SpisPrzystankow[i]->getNazwa()==Arg) CzyZnalziony=true;
        else ++i;
    }
    if(CzyZnalziony)return this->SpisPrzystankow[i];

    return nullptr;
}

void Siec::wypisz() {
    for(int i=0;i<this->IloscPrzystankow;++i){
        std::cout << "Przystanek " << this->SpisPrzystankow[i]->getNazwa() << " jego id: " << this->SpisPrzystankow[i]->getId();
        std::cout << " lat: " << std::setprecision(10) << this->SpisPrzystankow[i]->getLat() << " lon: " << std::setprecision(10)<<this->SpisPrzystankow[i]->getLon() << std::endl;
    }

}

int Siec::getIloscPrzystankow() const {
    return IloscPrzystankow;
}


/*
 * Metoda szukajaca przystanku o danym id
 *
 * Parametry:
 *  -id przystanku szukanego
 *
 * Zwraca:
 *  -wskaznik do przystanku jesli znaleziony
 *  -nullptr jesli nieznaleziony
 *
 */
Przystanek *Siec::ZnajdzPrzystanek(int id) const {
    int i=0;
    while(i!=this->IloscPrzystankow){
        if(this->SpisPrzystankow[i]->getId()==id) return this->SpisPrzystankow[i];
    }
    return nullptr;
}

Rozklad **Siec::getSpisLinii() const {
    return SpisLinii;
}


/*Metoda szukajaca czy w sieci jest przystanek o podanej nazwie rozny od juz znalezionych
 *
 * Parametry:
 *  -nazwa przystanku szukanego (string)
 *  -tablica ID juz znalezionych przystankow (int)
 *
 * Zwraca:
 *  -wskaznik do przystanku jesli znaleziony
 *  -nullptr jesli nie znaleziony
 *
 */
Przystanek *Siec::ZnajdzPrzystanek(std::string Arg, int tabID) const {
    int i = 0;
    while(i < this->IloscPrzystankow) {
        if(this->SpisPrzystankow[i]->getNazwa()==Arg) {
            bool CzyNowy = true;
            for(int j = 0; j < ROZMIAR; ++j) {
                if(this->SpisPrzystankow[i]->getId()==tabID[j]) {
                    CzyNowy = false;
                }
            }
            if(CzyNowy) {
                return this->SpisPrzystankow[i];
            }
        else ++i;
    }
    return nullptr;
}