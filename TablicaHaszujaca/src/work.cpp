//
// Created by maciek on 17.05.17.
//

#include "../inc/work.hh"

using namespace std;

void fglowna(Wariant& hasz,TabAso* uchwyt,Miernik& moj) {
    for (int i = 0; i < doktorejpozycjiwtablicywykonywac; ++i) {
        cout << "Dla rozmiaru tablicy rownego " << rozmiardotestow[i] << endl;
        bool mozna = true;
        try {
            uchwyt = new TabAso(rozmiardotestow[i]);
        }
        catch (bad_alloc) {
            cerr << "Problem z pamiecia" << endl;
            mozna = false;
        }
//-----szukane:
        string szukany = "szukany";
        int szukany2 = rozmiardotestow[i] + 1;

        try {
            uchwyt->zbuduj(szukany, szukany2, hasz);
        }
        catch (BrakMiejsca) {
            std::cerr << "Brakuje miejsca w tablicy" << std::endl;
        }
        catch (NieZnalezionoMiejsca){
            std::cerr << "Gdzies zly pointer" << std::endl;
        }
        if (mozna) {
            for (int j = 0; j < ilepomiarow; ++j) {

                moj.mierzczas(*uchwyt, szukany, szukany2, j, hasz);
            }
            cout << "Czas dla ilosci elementow:"<< rozmiardotestow[i] << ' ' << moj.wezsredni() << endl;
            moj.zapis_do_pliku(hasz);
            cout << "Po zapisie" << endl;
            moj.resetuj(ilepomiarow);
            cout << "Po resecie" << endl;


        }
        cout << endl << endl;
        delete uchwyt;
    }

}

void fglowna(Wariant& miejsceszukanego,Testowalny* uchwyt, Miernik& mojmiernik) {
    //tutaj za kazdym razem poszukiwanym elementem bedzie wartosc rowna rozmiarowi drzewa
    for(int i=0;i<doktorejpozycjiwtablicywykonywac;++i) {
        uchwyt = new bst;
        uchwyt->zbuduj("", rozmiardotestow[i], miejsceszukanego);


        for (int j = 0; j < ilepomiarow; ++j) {
//            cout << "Pomiar " << j << endl;
            mojmiernik.mierzczas(*uchwyt,"",rozmiardotestow[i],j,miejsceszukanego);
        }
        cout << "Czas dla ilosci elementow:" << rozmiardotestow[i] << ' ' << mojmiernik.wezsredni() << endl;
        mojmiernik.zapis_do_pliku(miejsceszukanego);
        mojmiernik.resetuj(ilepomiarow);

        cout << endl << endl;
    }

}
