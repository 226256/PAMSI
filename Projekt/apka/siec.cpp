#include "siec.h"

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
 *  -Wskaznik do pustej tablicy, gdy nie znaleziono jednego z przystankow
 *
 */
std::list<Przystanek*> Siec::ZnajdzNajkrotszaDroge(std::string Poczatek, std::string Koniec) const {
    //TODO tutaj stowrzyc algorytm wyszukiwania najkrotszej sciezki i zwracania tablicy z przystankami jakie trzeba odwiedzic

    std::list<Przystanek*> DoPrzejrzenia;
    std::list<Przystanek*> Przejrzane;
    std::list<Przystanek*> PoczatekLista;
    std::list<Przystanek*> PomocLista;
    std::list<Przystanek*> KoniecLista;
    std::list<Przystanek*> SpisTrasy;
    std::list<Przystanek*>::const_iterator it;
    std::list<Przystanek*>::const_iterator jt;
    std::list<Przystanek*>::const_iterator gt;
    Przystanek* Obecny;
    Przystanek* Koncowy;
    double lat = ZnajdzPrzystanek(Koniec)->getLat();
    double lon = ZnajdzPrzystanek(Koniec)->getLon();
    double pom;
    bool CzyKoniec = false;

    Obecny = ZnajdzPrzystanek(Poczatek);

//Wczytanie do listy wszystkich przystankow o nazwie "Poczatek"
    PoczatekLista = ZnajdzPrzystankiOtakiejNazwie(Poczatek);

//Wczytanie do listy wszystkich przystankow o nazwie "Koniec"
    KoniecLista = ZnajdzPrzystankiOtakiejNazwie(Koniec);

    if(PoczatekLista.empty() || KoniecLista.empty()) {
        return SpisTrasy;
    }

//Dodanie do listy DoPrzejrzenia wszystkich najbliższych przystankow dla wszystkich przystankow o nazwie "Poczatek",
//dadanie im pola "rodzic" i wyliczenie G, H, F
    for(it = PoczatekLista.begin(); it != PoczatekLista.end(); ++it) {
        for(jt = it.operator*()->getSasiadow().begin(); jt != it.operator*()->getSasiadow().end(); ++jt) {
            DoPrzejrzenia.push_front(*jt);
            jt.operator*()->DodajRodzica(*it);
            jt.operator*()->WyliczKoszt(lat, lon);
        }
    }

//Sprawdzenie czy nie mamy juz pola docelowego
    for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
        if(it.operator*()->getNazwa() == Koniec) {
            SpisTrasy.push_front(*it);
            SpisTrasy.push_front(it.operator*()->getRodzic());
            return SpisTrasy;
        }
    }
//Zmiana stanu pola poczatkowego
    Przejrzane.push_front(Obecny);


//Glowna petla algorytmu
    while(!CzyKoniec) {
    //Wybranie nastepnego punktu
        pom = 10000;
        for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
            if(pom > it.operator*()->getKoszt()) {
                pom = it.operator*()->getKoszt();
                Obecny = it.operator*();
            }
        }
    //Zmiana statusu obecnego pola
        for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
            if(it.operator*()->getId() == Obecny->getId()) {
                DoPrzejrzenia.erase(it);
                Przejrzane.push_front(Obecny);
                break;
            }
        }
    //Sprawdzenie przyleglych pol
        for(it = Obecny->getSasiadow().begin(); it != Obecny->getSasiadow().end(); ++it) {
            PomocLista = ZnajdzPrzystankiOtakiejNazwie(it.operator*()->getNazwa());
            for(gt = PomocLista.begin(); gt != PomocLista.end(); ++gt) {
                    bool JuzPrzejrzane = false, JuzBylo = false;
                    for(jt = Przejrzane.begin(); jt != Przejrzane.end(); ++jt) {
                        if(it.operator*()->getId() == jt.operator*()->getId()) {
                            JuzPrzejrzane = true;
                            break;
                        }
                    }
                    if(!JuzPrzejrzane) {
                        for(jt = DoPrzejrzenia.begin(); jt != DoPrzejrzenia.end(); ++jt) {
                            if(it.operator*()->getId() == jt.operator*()->getId()) {
                                JuzBylo = true;
                                break;
                            }
                        }
                        if(JuzBylo) {
                            //obliczenie odleglosci sasiada od obecnego
                            double temp;
                            temp = (Obecny->getLat()-it.operator*()->getLat())*(Obecny->getLat()-it.operator*()->getLat());
                            temp += (Obecny->getLon()-it.operator*()->getLon())*(Obecny->getLon()-it.operator*()->getLon());
                            temp = sqrt(temp) + it.operator*()->getG();
                                if(it.operator*()->getG() < temp) {
                                    it.operator*()->DodajRodzica(Obecny);
                                    it.operator*()->WyliczKoszt(lat,lon);
                                }
                            }
                        else {
                            DoPrzejrzenia.push_front(*it);
                            it.operator*()->DodajRodzica(Obecny);
                            it.operator*()->WyliczKoszt(lat, lon);
                            break;
                        }
                    }
            }
        }
    //Sprawdzenie czy nie mamy juz pola docelowego
        for(it = DoPrzejrzenia.begin(); it != DoPrzejrzenia.end(); ++it) {
            if(it.operator*()->getNazwa() == Koniec) {
                it.operator*()->DodajRodzica(Obecny);
                Koncowy = *it;
                CzyKoniec = true;
            }
        }
    }

//Wpisanie nazwy przystankow w dobrej kolejnosci
    if(CzyKoniec) {
        Przystanek *temp = Koncowy;
        while(temp->getRodzic() != nullptr) {
            SpisTrasy.push_front(temp);
            temp = temp->getRodzic();
        }
        SpisTrasy.push_front(temp);
    }

    return SpisTrasy;

}


/*
 * Metoda poszukujaca linii ktorymi mozna przejechac dana trase
 *
 * Parametry:
 *  -lista prszystankow, ktore nalezy odwiedzic (list<Przystanek*>)
 *
 * Zwraca:
 *  -wskaźnik na tablicę z numerami linii ktorymi nalezy sie poruszac
 *
 */



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

void Siec::setLiczbaLinii(int liczbaLinii) {
    Siec::liczbaLinii = liczbaLinii;
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
    return this->IloscPrzystankow;
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
//    std::cout << "Szukam id: " << id << std::endl;
    while(i!=this->IloscPrzystankow){
        if(this->SpisPrzystankow[i]->getId()==id) return this->SpisPrzystankow[i];
        ++i;
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
    std::list<Przystanek *>::iterator it;
    while (i < this->IloscPrzystankow) {
        if (this->SpisPrzystankow[i]->getNazwa() == Arg) {
            bool CzyNowy = true;
            for (it = listID.begin(); it != listID.end(); ++it) {
                if (this->SpisPrzystankow[i]->getId() == it.operator*()->getId()) {
                    CzyNowy = false;
                }
            }
            if (CzyNowy) {
                return this->SpisPrzystankow[i];
            } else ++i;
        }
        return nullptr;
    }
    return nullptr;
}


void Siec::OrganizujSiec() {
    for(int i=0;i<this->liczbaLinii;++i){
        int* tempIds=this->SpisLinii[i]->getId_nastepnych();
//        std::cout << this->SpisLinii[i]->getLinia() << ' ' << this->SpisLinii[i]->getWariant() << std::endl;
        int iloscNastepnych=tempIds[0];
        for(int j=1;j<iloscNastepnych-1;++j){
            Przystanek* uchwyt=this->ZnajdzPrzystanek(tempIds[j]);
            Przystanek* sasiad=this->ZnajdzPrzystanek(tempIds[j+1]);
            if(uchwyt!= nullptr && sasiad!= nullptr) {
//                std::cout << "Do " << uchwyt->getNazwa() << " dodaje sasiada " << sasiad->getNazwa() << std::endl;
                uchwyt->DodajSasiada(sasiad);
            }
            else{
                std::cerr << "Nie znajduje" << std::endl;

            }
        }
    }
}

std::list<Przystanek*> Siec::ZnajdzPrzystankiOtakiejNazwie(std::string Arg) const {
    int i=0;
    std::list<Przystanek*> temp;
    while(i<this->IloscPrzystankow){
        if(this->SpisPrzystankow[i]->getNazwa()==Arg) {
            temp.push_back(this->SpisPrzystankow[i]);
        }
        ++i;
    }
    return temp;
}

int Siec::getLiczbaLinii() const {
    return liczbaLinii;
}
