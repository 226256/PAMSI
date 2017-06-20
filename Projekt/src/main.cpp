#include <iostream>
#include "../inc/Rozklad.hh"
#include "../inc/Siec.hh"
#include "../inc/PracownikMPK.hh"

using namespace std;

int main() {

    Siec MPK;
    PracownikMPK::TworzTablicePrzystankow(MPK);
    PracownikMPK::StworzLinie(MPK);
    MPK.OrganizujSiec();


    auto lista = MPK.ZnajdzNajkrotszaDroge("Dubois", "GALERIA DOMINIKAŃSKA");

    for(list<Przystanek *>::iterator it=lista.begin();it!=lista.end();++it) {
        cout << it.operator*()->getNazwa() << ' ' << it.operator*()->getId() << endl;
    }

	return 0;
}