//
// Created by maciek on 17.05.17.
//

#include "../inc/work.hh"

using namespace std;

void fglowna(Wariant& hasz,TabAso* uchwyt,Miernik& moj) {
    for (int i = 0; i < doktorejpozycjiwtablicywykonywac; ++i) {
        cout << "Dla rozmiaru tablicy rownego " << rozmiartablicy[i] << endl;
        bool mozna = true;
        try {
            uchwyt = new TabAso(rozmiartablicy[i]);
        }
        catch (bad_alloc) {
            cerr << "Problem z pamiecia" << endl;
            mozna = false;
        }
//-----szukane:
        string szukany = "szukany";
        int szukany2 = rozmiartablicy[i] + 1;

        try {
            uchwyt->zbuduj(szukany, szukany2, hasz);
        }
        catch (BrakMiejsca) {
            std::cerr << "Brakuje miejsca w tablicy" << std::endl;
        }
        if (mozna) {
            for (int i = 0; i < ilepomiarow; ++i) {

                moj.mierzczas(*uchwyt, szukany, szukany2, i, hasz);
                std::cout << "kolko " << i <<endl;
            }
            cout << moj.wezsredni() << endl;
            moj.zapis_do_pliku(hasz);
            moj.resetuj(ilepomiarow);
        }
        cout << endl << endl;
    }

}