#include "mojatrasa.h"

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


    int integer=0;
    std::cout << "Zapisze sobie nazwy do tablicy" << std::endl << std::endl;
    for(auto it=this->MojePrzystankiNaTrasie.begin();it!=this->MojePrzystankiNaTrasie.end();++it){
        TablicaNazw[integer]=it.operator*()->getNazwa();
        ++integer;
    }

//    std::cout << "Jesli znaleziony biore" << std::endl;
    if(MozeBezposredni != nullptr){
        temp=new ParaLiniaPrzystanek [this->LiczbaPrzystankowDoPrzejechania];
        for (integer = 0; integer < this->LiczbaPrzystankowDoPrzejechania; ++integer) {
            temp[integer].linia=MozeBezposredni->getLinia();
            temp[integer].liniaznak=MozeBezposredni->getIdspec();
            temp[integer].przystanek=TablicaNazw[integer];
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
                    if (nastepne[j]==idobecnego) {
                        listaprzydatnychrozkladow.push_back(tempRozklady[i]);
                    }
                }
            }
            int rozm= (int) listaprzydatnychrozkladow.size();
            tabLiniiKtoreMajaMojPrzystanek = new Rozklad* [rozm];
            oplacalnoscLinii=new int [rozm];
            for (int m = 0; m < rozm; ++m) {
                oplacalnoscLinii[m]=0;
            }
            for (int k = 0; k < rozm; ++k) {
                tabLiniiKtoreMajaMojPrzystanek[k]=listaprzydatnychrozkladow.front();
                listaprzydatnychrozkladow.pop_front();
            }

            for (int l = 0; l < rozm; ++l) {//petla chodzenia po spisie przystankow ktore maja obecny przystanek
                int* SprawdzanePrzystanki=tabLiniiKtoreMajaMojPrzystanek[l]->getId_nastepnych();

                int dopetli=tabLiniiKtoreMajaMojPrzystanek[l]->IloscPrzystankowWLinii();

                for (auto it=obecny;it!=this->MojePrzystankiNaTrasie.end();++it) {//petla chodzenia po kolejnych przystankach do sprawdzania
                    for (int j = 1; j < dopetli; ++j) {//sprawdzanie kazdego przystanku na trasie czy jest rowny wlasnei szukanemu

                        if(it.operator*()->getId()==SprawdzanePrzystanki[j]) oplacalnoscLinii[l]+=1;
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
                listaDanychWyjsciowych.push_back(Paratemp);
                ++obecny;
            }

        }

        int IloscDanychWyjsciowych= (int) listaDanychWyjsciowych.size();
        temp=new ParaLiniaPrzystanek [IloscDanychWyjsciowych];
        for (int i1 = 0; i1 < IloscDanychWyjsciowych; ++i1) {
            temp[i1]=listaDanychWyjsciowych.front();
            listaDanychWyjsciowych.pop_front();
        }


        }
    //zwracam ale tez zapisuje od razu zeby potem miec w zanadrzu
    this->tablica=temp;
    return temp;
}





int MojaTrasa::getLiczbaPrzystankowDoPrzejechania() const {
    return LiczbaPrzystankowDoPrzejechania;
}
