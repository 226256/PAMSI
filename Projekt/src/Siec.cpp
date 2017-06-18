//
// Created by maciek on 31.05.17.
//

#include <list>
#include "../inc/Siec.hh"
#define ROZMIAR 40     // ilosc powtorzen przystankow


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
 *  -Wskaznik do tablicy przechowujacej nazwy przystankow przez ktore trzeba przejechac
 *  -nullptr jesli nie znaleziono jednego z przystankow podanych jako parametr
 *
 */
std::list<std::string> Siec::ZnajdzNajkrotszaDroge(std::string Poczatek, std::string Koniec) const {
    //TODO tutaj stowrzyc algorytm wyszukiwania najkrotszej sciezki i zwracania tablicy z przystankami jakie trzeba odwiedzic

    std::list<Przystanek*> DoPrzejrzenia;
    std::list<Przystanek*> Przejrzane;
    std::list<Przystanek*> PoczatekID;
    std::list<Przystanek*> KoniecID;
    std::list<Przystanek*> Trasa;
    std::list<std::string> SpisTrasy;
    std::list<Przystanek*>iterator it, jt;
    Przystanek* Obecny;
    Przystanek* Nastepny;
    double lat = ZnajdzPrzystanek(Koniec)->getLat;
    double lon = ZnajdzPrzystanek(Koniec)->getLon;
    double pom;

    Obecny = ZnajdzPrzystanek(Poczatek);
    DoPrzejrzenia.push_front(Obecny);

//Wczytanie do listy wszystkich przystankow o nazwie "Poczatek"
    PoczatekID.push_back(Obecny);
    bool CzyWszystkie = false;
    while(!CzyWszystkie) {
        Przystanek *temp;
        temp = ZnajdzPrzystanek(Poczatek, PoczatekID);
        if(temp != nullptr) {
            PoczatekID.push_back(temp);
        }
        else {
            CzyWszystkie = true;
        }
    }
//Wczytanie do listy wszystkich przystankow o nazwie "Koniec"
    KoniecID.push_back(ZnajdzPrzystanek(Koniec));
    bool CzyWszystkie = false;
    while(!CzyWszystkie) {
        Przystanek *temp;
        temp = ZnajdzPrzystanek(Koniec, KoniecID);
        if(temp != nullptr) {
            KoniecID.push_back(temp);
        }
        else {
            CzyWszystkie = true;
        }
    }

//Dodanie do listy DoPrzejrzenia wszystkich najbliższych przystankow dla wszystkich przystankow o nazwie "Poczatek"
    for(it = PoczatekID.begin(); it != PoczatekID.end(); ++it) {
	   	DoPrzejrzenia.push_front(it->);        //!!!DODAC!!!  POTRZEBA NASTEPNYCH PRZYSTANKOW
	   	it->UstawRodzica(Obecny);
	}
//Sprawdzenie czy nie mamy juz pola docelowego
	for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
		if(it->getNazwa() == Koniec) {
			SpisTrasy.push_front(Koniec);
			SpisTrasy.push_front(Start);
			return SpisTrasy;
		}
	}

//Wyliczenie kosztu zrobienia kroku i wybranie nastepnego punktu
	pom = 10000;
	for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
		it->WyliczKoszt(lat, lon);
		if(pom > it->getKoszt()) {
			pom = it->getKoszt();
			Nastepny = it;
		}
	}
//Zmiana statusu obecnego pola
	for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
		if(it->getId() == Obecny->getId()) {
			DoPrzejrzenia.erase(it);
			Przejrzane.push_front(Obecny);
			Obecny = Nastepny;
			break;
		}
	}
//Sprawdzenie przyleglych pol
	for(it) {  //!!!DODAC!!! - POTRZEBA NASTEPNYCH PRZYSTANKOW

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
 *  -lista juz znalezionych przystankow (list<Przystanek*>)
 *
 * Zwraca:
 *  -wskaznik do przystanku jesli znaleziony
 *  -nullptr jesli nie znaleziony
 *
 */
Przystanek *Siec::ZnajdzPrzystanek(std::string Arg, std::list<Przystanek*> listID) const {
    int i = 0;
    std::list<Przystanek*>iterator it;
    while(i < this->IloscPrzystankow) {
        if(this->SpisPrzystankow[i]->getNazwa()==Arg) {
            bool CzyNowy = true;
            for(it = listID.begin(); it != listID.end(); ++it) {
                if(this->SpisPrzystankow[i]->getId() == it->getId()) {
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