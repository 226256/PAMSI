#include "funkcje.hh"
#include <iostream>
#include <fstream>



void zapis_do_pliku(stoper& Dane,wariant& wybor){
    std::ofstream plik;

    if(wybor==pierwszy) plik.open("Alg_o_1.txt",std::ios::app);
    else if(wybor==drugi) plik.open("Alg_2n.txt",std::ios::app);


    if(plik.good()){
        plik << "\nNowa seria!\n Poszczegolne czasy algorytmu: \n";
        for(int i=0;i<POWTORZENIA;i++){
            plik << Dane.gCzasy(i) << " s\n";
        }
        plik << "Średni czas tej serii: " << Dane.gSrednia();


    }
    else std::cerr << "Nie mozna zapisac do pliku" << std::endl;
    plik.close();
}



void zawody(stoper& Miernik,wykonywalny& Obiekt,unsigned int rozmiar_pr,int powtorzenia){
    wariant Alg1=pierwszy,Alg2=drugi;



    Miernik.mierz_czas(Obiekt,rozmiar_pr,powtorzenia,Alg1);
    zapis_do_pliku(Miernik,Alg1);
    std::cout << "Sredni czas pierwszego algorytmu dla powiekszania o " <<  ROZMIARPROBLEMU << " wynosi: " << Miernik.gSrednia() << std::endl;
    Miernik.reset();

    Miernik.mierz_czas(Obiekt,rozmiar_pr,powtorzenia,Alg2);
    zapis_do_pliku(Miernik,Alg2);
    std::cout << "Sredni czas drugiego algorytmu dla powiekszania o " <<  ROZMIARPROBLEMU << " wynosi: " << Miernik.gSrednia() << std::endl;
    Miernik.reset();



}




