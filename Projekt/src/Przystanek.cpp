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

Przystanek::~Przystanek() {
    this->ilosc_linii=0;
    delete this->numery_linii;

}

//-----------------------------------------------------------------------------------------------------





//-----------------------metody get------------

const std::string &Przystanek::getNazwa() const {
    return this->nazwa;
}

int *Przystanek::getNumery_linii() const {
    return numery_linii;
}

Rozklad *Przystanek::ZnajdzLinie(int& szukana_linia) const{
    int i=0;
    bool CzyZnaleziona=false;
    Rozklad* temp= nullptr;
    while (i!=this->ilosc_linii && !CzyZnaleziona){
        if(this->numery_linii[i]==szukana_linia){CzyZnaleziona = true;}
        ++i;
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


