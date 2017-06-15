//
// Created by maciek on 06.06.17.
//

#include "../inc/PracownikMPK.hh"


void PracownikMPK::TworzTablicePrzystankow(Siec& Arg) {

    std::list<Przystanek*> listaPrzystankow;    //lista w ktorej bede przechowywal wczytane nazwy
    Przystanek* temp = nullptr;                 //wskaznik na tymczasowy przystanek ktory zostanie dodany do listy

    std::string* tymczasowaNazwa;               //nazwa ktora pobieram z kazdej linii a dzieki niej tworze przystanek
    std::stringstream strumien;                 //strumien potrzebny do wyciagniecia id z linii
    int tymczasoweId=0;                         //zmienna przechowujaca id
    std::string *tymczasowelat;
    std::string *tymczasowelon=0;
    double lat;
    double lon;


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
            size_t przecinek_przed_lon=bufor.find_last_of(",");
            size_t przecinek_przed_lat=bufor.find_last_of(",",przecinek_przed_lon-1);

            strumien.str("");
            strumien.clear();
            tymczasowelat=new std::string(bufor,przecinek_przed_lat+1,przecinek_przed_lon-przecinek_przed_lat-1);
            tymczasowelon=new std::string(bufor,przecinek_przed_lon+1);
            strumien << *tymczasowelat;
            strumien >> lat;

            strumien.str("");
            strumien.clear();
            strumien << *tymczasowelon;
            strumien >> lon;


            tymczasowaNazwa=new std::string(bufor,found+1,secondfound-found-1);  //oddzielam sobie nazwe przystanku
            temp=new Przystanek(tymczasoweId,*tymczasowaNazwa,lat,lon);                              //tworze przystanek
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

Rozklad **PracownikMPK::StworzLinie(Siec& Arg) {
    Rozklad** TablicaLinii=new Rozklad* [469];
    std::fstream plik;
    int intdolinii;
    char chardolinii;
    std::string *tmpdolinii;

    std::stringstream strumien;
    std::string bufor;
    std::string *temp;
    int doid;
    size_t pierwszyPrzecinek;
    size_t drugiPrzecinek;
    size_t podkreslnik;
    int* id=new int[2];

    std::string nazwy[]={
            "../Pliki/TripsOnlyNumbers.txt",
            "../Pliki/Trips0.txt",
            "../Pliki/Trips900.txt",
            "../Pliki/TripsOnlyLetters.txt"
    };

    for (int j = 0; j < 4; ++j) {
        plik.open(nazwy[j], std::ios::in);
        int i = 0;
        while (!plik.eof()) {
            std::getline(plik, bufor);
            pierwszyPrzecinek = bufor.find_first_of(",");
            drugiPrzecinek = bufor.find_first_of(",", pierwszyPrzecinek + 1);
            if(j==0){
                tmpdolinii=new std::string(bufor, 0, pierwszyPrzecinek);
                strumien << *tmpdolinii;
                strumien >> intdolinii;
                chardolinii = ';';
            }
            else if(j==1){
                intdolinii=0;
                chardolinii = bufor[1];
            }
            else if (j==2){
                tmpdolinii=new std::string(bufor,0,3);
                strumien << *tmpdolinii;
                strumien >> intdolinii;
                chardolinii = bufor[3];
            }
            else{
                intdolinii=1111;
                chardolinii=bufor[0];
            }


            temp = new std::string(bufor, drugiPrzecinek + 1, 1);
            strumien << temp;
            strumien >> doid;
            strumien.str("");
            strumien.clear();
            id[0] = doid;

            temp = new std::string(bufor, drugiPrzecinek + 3, 7);
            strumien << temp;
            strumien >> doid;
            id[1] = doid;
            strumien.str("");
            strumien.clear();

            TablicaLinii[i] = new Rozklad(id,intdolinii,chardolinii);
            ++i;
        }
        plik.close();
    }



}