#include <iostream>
#include "../inc/Rozklad.hh"
#include "../inc/Siec.hh"
#include "../inc/PracownikMPK.hh"

using namespace std;

int main() {
    Siec MPK;
    PracownikMPK::TworzTablicePrzystankow(MPK);
    PracownikMPK::StworzLinie(MPK);
//    MPK.wypisz();
//    cout << "Ilosc Przystankow we Wroclawiu: " << MPK.getIloscPrzystankow() << endl;
    return 0;
}