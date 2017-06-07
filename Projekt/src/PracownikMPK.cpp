//
// Created by maciek on 06.06.17.
//

#include "../inc/PracownikMPK.hh"


void PracownikMPK::TworzTablicePrzystankow(Siec& Arg) {
    /*
     * Trzeba zrobic cos w ten desen
     * wczytujesz po kolei kazdy folder tymczasoweId kazdy plik
     * sa w nim tam po kolei kazde przystanki wiec najpierw trzeba sprawdzic czy takiego przystanku jeszcze nie ma
     * pierwsza przystanek na trasie ma zapisane wszystkie pozostale wiec mozna sobie od razu utwprzyc tablice
     * Przystanek* tablica z odpowiednio przeliczona liczba elementow
     *
     * Kazdy przystanek mozesz tworzyc na dwa sposoby, albo najpierw przystanek ma sama nazwe a potem ustawiasz reszte
     * albo od razu wszystko
     * tymczasoweId na przyklad mozesz sobie przechowywac kolejne przystanki w liscie zeby na koniec wszystko po kolei wrzucic do grafu
     * wczesniej po kolei tworzac ze wskaznikow do nich wielka tablice
     *
     *  Przyklad tego co wymyslilem na dole(moze byc slabe, jesli masz lepszy pomysl dobrze bedzie zmienic)
     *  Trzeba tylko wymyslic jakis sposob jak to wczytywac z pliku
     *
     */
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
