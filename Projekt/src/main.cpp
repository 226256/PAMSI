#include <iostream>
#include "../inc/Rozklad.hh"
#include "../inc/Siec.hh"
#include "../inc/PracownikMPK.hh"

using namespace std;

int main() {
    Siec MPK;
    PracownikMPK::TworzTablicePrzystankow(MPK);
    MPK.wypisz();
    return 0;
}