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
    this->czasy=new long double [ilepomiarow];
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

void Miernik::resetuj(int iloscpomiarow) {
    for(int i=0;i<ilepomiarow;++i){
        czasy[i]=0;
    }
    this->srednia=0;
    this->poczatek=0;
    this->koniec=0;
}


void Miernik::mierzczas(Testowalny & Arg,std::string stringdotestow,int wartoscdotestow,int nrokrazenia,Wariant hasz) {
    this->start();
    Arg.zadanie(stringdotestow);
    this->stop();
    this->czasy[nrokrazenia]=(this->koniec-this->poczatek)/(long double)CLOCKS_PER_SEC;
    std::cout << this->czasy[nrokrazenia]<< std::endl;
}


long double Miernik::wezsredni() {
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
	else return 0;
}

void Miernik::zapis_do_pliku(Wariant& wybor) {
    char znak='T';

//    std::cout << "Czy zapisac do pliku?[T/n] ";
//    std::cin >> znak;
//    std::cout << znak << std::endl;
//    int proby=0;
//    while(znak!='n'&& znak!='T'){
//        ++proby;
//        if(proby==5){ return;}
//        std::cout << "Bledna odpowiedz.Czy zapisac do pliku?[T/n] ";
//        std::cin >> znak;
//    }
    if(znak=='n'){return;}
    else{
        std::ofstream plik;
        if(wybor==pierwszy) plik.open("Haszowanie_modularne.txt",std::ios::app);
        else if(wybor==drugi) plik.open("Haszowanie przez mnozenie.txt",std::ios::app);


        if(plik.good()){
            plik << "\nNowa seria!\n Poszczegolne czasy algorytmu: \n";
            for(int i=0;i<ilepomiarow;++i){
                plik << this->czasy[i] << " s\n";
            }
            plik << "Średni czas tej serii: " << this->wezsredni();
        }
        else std::cerr << "Nie mozna zapisac do pliku" << std::endl;
        plik.close();
    }
}
