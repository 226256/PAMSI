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


    auto temp=MPK.ZnajdzPrzystankiOtakiejNazwie("GRABISZYŃSKA (Cmentarz)");

    for(list<Przystanek *>::iterator it=temp.begin();it!=temp.end();++it) {
        cout << it.operator*()->getNazwa() << ' ' << it.operator*()->getId() << endl;
    }
    return 0;
}