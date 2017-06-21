#include <iostream>
#include "../inc/Rozklad.hh"
#include "../inc/Siec.hh"
#include "../inc/PracownikMPK.hh"
#include "../inc/MojaTrasa.hh"


using namespace std;

int main() {

    Siec MPK;
    PracownikMPK::TworzTablicePrzystankow(MPK);
    PracownikMPK::StworzLinie(MPK);
    MPK.OrganizujSiec();


    auto lista = MPK.ZnajdzNajkrotszaDroge("Park Zachodni", "Niedźwiedzia");
    MojaTrasa* trasa=new MojaTrasa(lista);
    ParaLiniaPrzystanek* tablica=trasa->WytyczTrase(MPK);


    for(list<Przystanek *>::iterator it=lista.begin();it!=lista.end();++it) {
        cout << it.operator*()->getNazwa() << ' ' << it.operator*()->getId() << endl;
    }

    if(tablica!= nullptr) {
        for (int i = 0; i < trasa->getLiczbaPrzystankowDoPrzejechania(); ++i) {
            if (tablica->liniaznak == ';' && tablica->linia!=1111)
                cout << "Linia " << tablica[i].linia << " Przystanek " << tablica[i].przystanek << endl;
            else if (tablica->linia == 1111)
                cout << "Linia " << tablica[i].liniaznak << " Przystanek " << tablica[i].przystanek << endl;
            else
                cout << "Linia " << tablica[i].linia << tablica[i].liniaznak << " Przystanek " << tablica[i].przystanek
                     << endl;
        }
    }
    else cout << "Brak trasy" << endl;
	return 0;
}