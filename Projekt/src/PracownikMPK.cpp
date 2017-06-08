//
// Created by maciek on 06.06.17.
//

#include "../inc/PracownikMPK.hh"


void PracownikMPK::TworzTablicePrzystankow(Siec& Arg) {

    std::list<Przystanek*> listaPrzystankow;    //lista w ktorej bede przechowywal wczytane nazwy
    Przystanek* temp = nullptr;                 //wskaznik na tymczasowy przystanek ktory zostanie dodany do listy

    std::string* tymczasowaNazwa;               //nazwa ktora pobieram z kazdej linii a dzieki niej tworze przystanek
    std::stringstream strumien;                 //strumien potrzebny do wyciagniecia id z linii
    int tymczasoweId;                         //zmienna przechowujaca id

    std::fstream spisprzystankow;               //strumien do pliku
    std::string bufor;                          //zmienna przechowujaca linie z pliku

    spisprzystankow.open("../Pliki/stops.txt",std::ios::in);
    if(!spisprzystankow.good()){
        throw BladPrzyOdczycieDanych();
    }
    else {
        std::getline(spisprzystankow,bufor);                        //pomijam pierwsza linei pliku po prostu wczytujac dwa razy
        std::getline(spisprzystankow,bufor);
        while(!spisprzystankow.eof()){
            strumien << bufor;
            strumien >> tymczasoweId;
            size_t found=bufor.find_first_of("\"");                 //szukam pierwszego wystapienia "
            size_t secondfound=bufor.find_first_of("\"",found+1);   //szukam drugiego wystapienia
            tymczasowaNazwa=new std::string(bufor,found+1,secondfound-found-1);  //oddzielam sobie nazwe przystanku
            temp=new Przystanek(*tymczasowaNazwa,tymczasoweId);                              //tworze przystanek
            listaPrzystankow.push_back(temp);
            strumien.str("");
            strumien.clear();
            std::getline(spisprzystankow,bufor);                    //pobieram linie z pliku

        }

        //tutaj zajmuje sie Tworzeniem sieci
        size_t dlugosclisty=listaPrzystankow.size();
        Arg.setIloscprzystankow((int) dlugosclisty);
        Przystanek** tablica=new Przystanek* [dlugosclisty];
        for(size_t i=0;i<dlugosclisty;++i){
            tablica[i]=listaPrzystankow.front();
            listaPrzystankow.pop_front();
        }
        Arg.setSpisPrzystankow(tablica);
        //teraz siec powinna miec spis przystankow
    }

}
