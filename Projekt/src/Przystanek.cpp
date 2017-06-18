//
// Created by maciek on 31.05.17.
//

#include "../inc/Przystanek.hh"

//---------------------konstruktory i destruktory------------------------------------------------------
Przystanek::Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii,
                       Rozklad **TablicaPoszczegolnychRozkladow) : nazwa(nazwa), ilosc_linii(ilosc_linii),
                                                                   numery_linii(numery_linii),
                                                                   TablicaPoszczegolnychRozkladow(
                                                                           TablicaPoszczegolnychRozkladow) {}

Przystanek::Przystanek(const std::string &nazwaNowego,int& idNowego) : nazwa(nazwaNowego), id(idNowego){}

Przystanek::~Przystanek() {
    this->ilosc_linii=0;
    delete this->numery_linii;

}

Przystanek::Przystanek(int id, const std::string &nazwa, double lat, double lon) : id(id), nazwa(nazwa), lat(lat),
                                                                                   lon(lon) {}
//-----------------------------------------------------------------------------------------------------





//-----------------------metody get i set------------

const std::string &Przystanek::getNazwa() const {
    return this->nazwa;
}

int *Przystanek::getNumery_linii() const {
    return numery_linii;
}

int Przystanek::getId() const {
    return id;
}


double Przystanek::getLat() const {
    return lat;
}

double Przystanek::getLon() const {
    return lon;
}

int Przystanek::getKoszt() const {
	return koszt;
}

Przystanek *Przystanek::getRodzic() const {
	return rodzic;
}


void Przystanek::setRodzic(Przystanek *Rodzic) {
	rodzic = Rodzic;
}

//----------------------------------------------------------------



Rozklad *Przystanek::ZnajdzLinie(int szukana_linia) const{
    int i=0;
    bool CzyZnaleziona=false;
    Rozklad* temp= nullptr;
    while (i!=this->ilosc_linii && !CzyZnaleziona){
        if(this->numery_linii[i]==szukana_linia){CzyZnaleziona = true;}
        else ++i;
    }
    if(CzyZnaleziona){
        int j=0;
        while(temp== nullptr){
            if(this->TablicaPoszczegolnychRozkladow[j]->getLinia()==szukana_linia) temp=this->TablicaPoszczegolnychRozkladow[j];
            ++j;
        }
    }
    return temp;
}

Rozklad *Przystanek::ZnajdzLinie(std::string Arg) const {
    int i=0;
    bool CzyZnaleziona=false;
    Rozklad* temp= nullptr;
    while (i!=this->ilosc_linii && !CzyZnaleziona){
        if(this->TablicaPoszczegolnychRozkladow[i]->getWariant()==Arg){CzyZnaleziona = true;}
        else ++i;
    }
    if(CzyZnaleziona){
        temp=this->TablicaPoszczegolnychRozkladow[i];
    }
    return temp;
}


void Przystanek::WyliczKoszt(double szerokosc, double dlugosc, int ID) {
	koszt = (int)sqrt((lat-szerokosc)*(lat-szerokosc) + (lon-dlugosc)*(lon-dlugosc));
//Dodajemy czas przejscia do tego punktu od rodzica
//	koszt += ;
}


