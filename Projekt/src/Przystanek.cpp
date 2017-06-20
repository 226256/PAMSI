//
// Created by maciek on 31.05.17.
//

#include "../inc/Przystanek.hh"

//---------------------konstruktory i destruktory------------------------------------------------------
//Przystanek::Przystanek(const std::string &nazwa, int ilosc_linii, int *numery_linii,
//                       Rozklad **TablicaPoszczegolnychRozkladow) : nazwa(nazwa), ilosc_linii(ilosc_linii),
//                                                                   numery_linii(numery_linii),
//                                                                   TablicaPoszczegolnychRozkladow(
//                                                                           TablicaPoszczegolnychRozkladow) {}

Przystanek::Przystanek(const std::string &nazwaNowego,int& idNowego) : nazwa(nazwaNowego), id(idNowego){}

Przystanek::~Przystanek() {
    this->ilosc_linii=0;
    delete this->numery_linii;

}

Przystanek::Przystanek(int id, const std::string &nazwa, double lat, double lon) : id(id), nazwa(nazwa), lat(lat),
                                                                                   lon(lon) {}
//-----------------------------------------------------------------------------------------------------





//-----------------------metody get------------

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

double Przystanek::getKoszt() const {
	return koszt;
}

double Przystanek::getG() const {
	return G;
}

double Przystanek::getH() const {
	return H;
}

Przystanek *Przystanek::getRodzic() const {
	return rodzic;
}



//----------------------------------------------------------------



//Rozklad *Przystanek::ZnajdzLinie(int szukana_linia) const{
//    int i=0;
//    bool CzyZnaleziona=false;
//    Rozklad* temp= nullptr;
//    while (i!=this->ilosc_linii && !CzyZnaleziona){
//        if(this->numery_linii[i]==szukana_linia){CzyZnaleziona = true;}
//        else ++i;
//    }
//    if(CzyZnaleziona){
//        int j=0;
//        while(temp== nullptr){
//            if(this->TablicaPoszczegolnychRozkladow[j]->getLinia()==szukana_linia) temp=this->TablicaPoszczegolnychRozkladow[j];
//            ++j;
//        }
//    }
//    return temp;
//}
//
//Rozklad *Przystanek::ZnajdzLinie(std::string Arg) const {
//    int i=0;
//    bool CzyZnaleziona=false;
//    Rozklad* temp= nullptr;
//    while (i!=this->ilosc_linii && !CzyZnaleziona){
//        if(this->TablicaPoszczegolnychRozkladow[i]->getWariant()==Arg){CzyZnaleziona = true;}
//        else ++i;
//    }
//    if(CzyZnaleziona){
//        temp=this->TablicaPoszczegolnychRozkladow[i];
//    }
//    return temp;
//}


void Przystanek::WyliczKoszt(double szerokosc, double dlugosc) {
	//heurystyka
	H = sqrt((lat - szerokosc)*(lat - szerokosc) + (lon - dlugosc)*(lon - dlugosc));
	//koszt przejścia od rodzica
	G = sqrt((lat - rodzic->getLat())*(lat - rodzic->getLat()) + (lon - rodzic->getLon())*(lon - rodzic->getLon()));
	//calosc funkcji F
	koszt = H + G;
}

void Przystanek::DodajSasiada(Przystanek *Arg) {
    if (Arg!= nullptr){
        this->Sasiedzi.push_back(Arg);
    } else std::cerr << "Brak Przystanku" << std::endl;

}

void Przystanek::DodajRodzica(Przystanek *Rodzic) {
	rodzic = Rodzic;
}

const std::list<Przystanek *> &Przystanek::getSasiadow() const {
    return Sasiedzi;
}

void Przystanek::DodajLiniePrzejezdzajaca(int *Arg) {
    this->LinieJakiePrzejezdzajaPrzezPrzystanek.push_back(Arg);

}
