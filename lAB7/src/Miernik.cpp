//
// Created by maciek on 06.05.17.
//

#include "../inc/Miernik.hh"

/*****************konstruktory i destruktory i takie tam ************/
void Miernik::start() {
    this->poczatek=clock();
}

void Miernik::stop() {
    this->koniec=clock();
}

Miernik::Miernik():poczatek(0),koniec(0),srednia(0){
    this->czasy= nullptr;
    this->rozm=0;
}

Miernik::Miernik(int ilepomiarow):poczatek(0),koniec(0),srednia(0){
    this->czasy=new double [ilepomiarow];
    for(int i=0;i<ilepomiarow;++i){
        czasy[i]=0;
    }
    this->rozm=ilepomiarow;
}

Miernik::~Miernik() {
    this->srednia=0;
    this->poczatek=0;
    this->koniec=0;
    this->czasy = nullptr;
}

void Miernik::resetuj(int ilepomiarow) {
    for(int i=0;i<ilepomiarow;++i){
        czasy[i]=0;
    }
    this->srednia=0;
    this->poczatek=0;
    this->koniec=0;
}


void Miernik::mierzczas(Testowalny & Arg,std::string stringdotestow,int wartoscdotestow,int nrokrazenia,Wariant hasz) {
    try {
        Arg.zbuduj(stringdotestow, wartoscdotestow, hasz);
    }
    catch(BrakMiejsca){
        std::cerr << "To tutaj " << std::endl;
    }
    this->start();
    Arg.zadanie(stringdotestow);
    this->stop();
    czasy[nrokrazenia]=(this->koniec-this->poczatek)/(double)CLOCKS_PER_SEC;
}


double Miernik::wezsredni() {
    if (rozm != 0) {
        double suma = 0;
        for (int i = 0; i < this->rozm; ++i) {
            suma += czasy[i];
        }
        return suma / this->rozm;
    }

    else if(rozm<=0){
        std::cerr << "Brak czasow" << std::endl;
        return 1;
    }
}