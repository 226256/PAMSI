//
// Created by maciek on 20.06.17.
//

#include "../inc/MojaTrasa.hh"

MojaTrasa::MojaTrasa(const list<Przystanek *> &MojePrzystankiNaTrasie)
        : MojePrzystankiNaTrasie(MojePrzystankiNaTrasie){
    this->LiczbaPrzystankowDoPrzejechania= (int) (MojePrzystankiNaTrasie.size());
}


MojaTrasa::~MojaTrasa() {
}


Rozklad *MojaTrasa::SprawdzCzyNieMaBezposredniego(Siec &Arg) {
    Rozklad** tempRozklady=Arg.getSpisLinii();
    int tempLiczbaRozkladow=Arg.getLiczbaLinii();
    for (int i = 0; i < tempLiczbaRozkladow; ++i) {
        int* nastepne=tempRozklady[i]->getId_nastepnych();
//        std::cout << "Sprawdzam linie " << tempRozklady[i]->getLinia() << " kierunek " << tempRozklady[i]->getWariant() << std::endl;
        int dlug=nastepne[0];
        bool PoczatekZnalezionywTrasie=false;
        bool KoniecZnalezionywTrasie= false;
        for (int j = 1; j < dlug; ++j) {
            if(this->MojePrzystankiNaTrasie.front()->getId()==nastepne[j]) {
//                std::cout << "Pierwszy znaleziony" << std::endl;
                PoczatekZnalezionywTrasie= true;
            }
            if(PoczatekZnalezionywTrasie && this->MojePrzystankiNaTrasie.back()->getId()==nastepne[j]) {
//                std::cout << "Drugi znaleziony" << std::endl;
                KoniecZnalezionywTrasie= true;
            }
            if(PoczatekZnalezionywTrasie && KoniecZnalezionywTrasie) {
//                std::cout << "Znalezione" << std::endl;
                return tempRozklady[i];
            }
        }


    }

    return nullptr;
}


ParaLiniaPrzystanek *MojaTrasa::WytyczTrase(Siec &Arg) {
//    std::cout << "Najpierw sprawdzam bezposrednie" << std::endl;
    Rozklad* MozeBezposredni=this->SprawdzCzyNieMaBezposredniego(Arg);
    ParaLiniaPrzystanek* temp = nullptr;
    string* TablicaNazw=new string [this->LiczbaPrzystankowDoPrzejechania];
    TablicaNazw[0]=this->MojePrzystankiNaTrasie.front()->getNazwa();
    TablicaNazw[this->LiczbaPrzystankowDoPrzejechania-1]=this->MojePrzystankiNaTrasie.back()->getNazwa();


    int i=0;
//    std::cout << "Zapisze sobie nazwy do tablicy" << std::endl << std::endl;
    for(auto it=this->MojePrzystankiNaTrasie.begin();it!=this->MojePrzystankiNaTrasie.end();++it){
        std::cout << it.operator*()->getNazwa() << std::endl;
        TablicaNazw[i]=it.operator*()->getNazwa();
//        std::cout << "i= " << ++i<< std::endl;
    }

//    std::cout << "Jesli znaleziony biore" << std::endl;
    if(MozeBezposredni != nullptr){
        temp=new ParaLiniaPrzystanek [this->LiczbaPrzystankowDoPrzejechania];
        for (i = 0; i < this->LiczbaPrzystankowDoPrzejechania; ++i) {
            temp[i].linia=MozeBezposredni->getLinia();
            temp[i].liniaznak=MozeBezposredni->getIdspec();
            temp[i].przystanek=TablicaNazw[i];
        }
    }


    else{
        Rozklad** tempRozklady=Arg.getSpisLinii();
        int tempLiczbaRozkladow=Arg.getLiczbaLinii();
        std::list<Rozklad*> listaprzydatnychrozkladow;
        auto obecny=this->MojePrzystankiNaTrasie.begin();
        std::list<ParaLiniaPrzystanek> listaDanychWyjsciowych;
        
        Rozklad** tabLiniiKtoreMajaMojPrzystanek;
        int* oplacalnoscLinii;
        while (obecny!=this->MojePrzystankiNaTrasie.end()) {
            int idobecnego=obecny.operator*()->getId();
            for (int i = 0; i < tempLiczbaRozkladow; ++i) {
                int *nastepne = tempRozklady[i]->getId_nastepnych();
                int dlug = nastepne[0];
                for (int j = 1; j < dlug; ++j) {
                    if (nastepne[j]==idobecnego) listaprzydatnychrozkladow.push_back(tempRozklady[i]);
                }
            }
            int rozm= (int) listaprzydatnychrozkladow.size();
            tabLiniiKtoreMajaMojPrzystanek = new Rozklad* [rozm];
            oplacalnoscLinii=new int [rozm];
            for (int m = 0; m < rozm; ++m) {
                oplacalnoscLinii[m]=0;
            }
            for (int k = 0; k < listaprzydatnychrozkladow.size(); ++k) {
                tabLiniiKtoreMajaMojPrzystanek[i]=listaprzydatnychrozkladow.front();
                listaprzydatnychrozkladow.pop_front();
            }

            for (int l = 0; l < rozm; ++l) {//petla chodzenia po spisie przystankow ktore maja obecny przystanek
                int* nastepne=tabLiniiKtoreMajaMojPrzystanek[l]->getId_nastepnych();

//TUTAJ WYSKAKUJE SEGMENT, NIE WIEM JAK
                for (auto it=obecny;it!=this->MojePrzystankiNaTrasie.end();++it) {//petla chodzenia po kolejnych przystankach do sprawdzania
                    for (int j = 1; j < nastepne[0]; ++j) {//sprawdzanie kazdego przystanku na trasie czy jest rowny wlasnei szukanemu
                        std::cout << "Nastepne nr " << j << " : " << nastepne[j] << std::endl;

                        if(it.operator*()->getId()==nastepne[j]) oplacalnoscLinii[l]+=1;
                    }

                }
            }

            int najwyzszy=0;
            for (int n = 1; n < rozm; ++n) {
                if(oplacalnoscLinii[n]>oplacalnoscLinii[najwyzszy])najwyzszy=n;
            }




            for(int o=0;o < oplacalnoscLinii[najwyzszy];++o) {
                ParaLiniaPrzystanek Paratemp;
                Paratemp.liniaznak=tabLiniiKtoreMajaMojPrzystanek[najwyzszy]->getIdspec();
                Paratemp.przystanek=obecny.operator*()->getNazwa();
                Paratemp.linia=tabLiniiKtoreMajaMojPrzystanek[najwyzszy]->getLinia();
                ++obecny;
            }

        }




        }
    //zwracam ale tez zapisuje od razu zeby potem miec w zanadrzu
    this->tablica=temp;
    return temp;
}





int MojaTrasa::getLiczbaPrzystankowDoPrzejechania() const {
    return LiczbaPrzystankowDoPrzejechania;
}




