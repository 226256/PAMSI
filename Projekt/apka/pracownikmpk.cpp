#include "pracownikmpk.h"

/*
 * Pierwsza funkcja wczytuje do sieci wszystkie mozliwe przystanki
 *
 * Druga funkcja wczytuje wszystkie linie we wroclawiu
 *
 */

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
        Arg.setIloscPrzystankow((int) dlugosclisty);
        Przystanek** tablica=new Przystanek* [dlugosclisty];
        for(size_t i=0;i<dlugosclisty;++i){
            tablica[i]=listaPrzystankow.front();
            listaPrzystankow.pop_front();
        }
        Arg.setSpisPrzystankow(tablica);
        //teraz siec powinna miec spis przystankow
    }


    std::cout << "Wczytano przystanki" << std::endl;
}



void PracownikMPK::StworzLinie(Siec& Arg) {
    int iloscLinii=469;
    Rozklad** TablicaLinii=new Rozklad* [iloscLinii];
    for(int i=0;i<iloscLinii;++i){
        TablicaLinii[i] = nullptr;
    }
    std::fstream plik;
    int intdolinii;
    char chardolinii;
    std::string *tmpdolinii,*stringdofunkcji;


    std::stringstream strumien;
    std::string bufor;
    std::string *temp;
    std::string *nazwaLinii;
    int doid;
    size_t pierwszyPrzecinek,drugiPrzecinek,pierwszyCudzyslow,drugiCudzyslow;

    int* id=new int[2];

    std::string nazwy[]={
            "../Pliki/TripsOnlyNumbers.txt",
            "../Pliki/Trips0.txt",
            "../Pliki/Trips900.txt",
            "../Pliki/TripsOnlyLetters.txt"
    };

    int i = 0;

    for (int j = 0; j < 4; ++j) {
        plik.open(nazwy[j], std::ios::in);
        while (!plik.eof()) {
            std::getline(plik, bufor);
            pierwszyPrzecinek = bufor.find_first_of(",");
            drugiPrzecinek = bufor.find_first_of(",", pierwszyPrzecinek + 1);
            pierwszyCudzyslow=bufor.find_first_of("\"");
            drugiCudzyslow=bufor.find_last_of("\"");
            if(j==0){
                tmpdolinii=new std::string(bufor, 0, pierwszyPrzecinek);
                strumien << *tmpdolinii;
                strumien >> intdolinii;
                strumien.str("");
                strumien.clear();
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
                strumien.str("");
                strumien.clear();
                chardolinii = bufor[3];
            }
            else{
                intdolinii=1111;
                chardolinii=bufor[0];
            }


            temp = new std::string(bufor, drugiPrzecinek + 1, 1);
            strumien << *temp;
            strumien >> doid;
            strumien.str("");
            strumien.clear();
            id[0] = doid;

            temp = new std::string(bufor, drugiPrzecinek + 3, 7);
            strumien << *temp;
            strumien >> doid;
            id[1] = doid;
            strumien.str("");
            strumien.clear();

            stringdofunkcji=new std::string(bufor,drugiPrzecinek+1,9);

            nazwaLinii=new std::string(bufor,pierwszyCudzyslow+1,drugiCudzyslow-pierwszyCudzyslow-1);
            int* tab=PobierzNastepne(*stringdofunkcji);

            TablicaLinii[i] = new Rozklad(id,intdolinii,chardolinii,*nazwaLinii,tab);
            ++i;
        }
        plik.close();
    }


    std::cout << "Wczytano linie" << std::endl;
    Arg.setSpisLinii(TablicaLinii);
    Arg.setLiczbaLinii(iloscLinii);
}

int* PracownikMPK::PobierzNastepne(std::string& ajdi) {

    /*
     * tutaj bede dodawal do kazdego rozkladu spis z nastepnymi przystankami
     * potrzebne mi jest id(bo sa w formacie np. 3_7292018)
     * oraz cos dzieki czemu nie bede szukal dalej jak juz wszystko znalazlem czyli:
     * fazy szukania:
     * fazyszukania=1;----zaczynam szukac;
     * fazyszukania=2;----znalazlem pierwsze wystapienie;
     * fazyszukania=3;----wystapienie bylo ale sie skonczylo(juz wiecej nie wystapi) koncze szukanie, biore kolejne id
     *
     *
     */

    int fazyszukania=0;
    std::list<int> numerynastepnych;
    std::fstream plik;
    std::string bufor;
    std::string* tempid,*tmpdostrumienia;
    std::stringstream nanumer;
    int ostatecznynrprzystanku;
    size_t pierwszyprzecinek,przecinekprzedidprzystankow,przecinekpoidprzystankow;

    plik.open("../Pliki/stop_timesNew.txt",std::ios::in);
    while(fazyszukania!=3 && !plik.eof()){
        fazyszukania=1;
        std::getline(plik,bufor);
        pierwszyprzecinek=bufor.find_first_of(",");
        przecinekprzedidprzystankow=bufor.find_first_of(",",pierwszyprzecinek+15);
        przecinekpoidprzystankow=bufor.find_first_of(",",przecinekprzedidprzystankow+1);
        tempid=new std::string(bufor,0,pierwszyprzecinek);
        if(ajdi==(*tempid) && fazyszukania==1) fazyszukania=2;
        if(ajdi==(*tempid)){
            tmpdostrumienia=new std::string(bufor,przecinekprzedidprzystankow+1,przecinekpoidprzystankow-przecinekprzedidprzystankow);
            nanumer << *tmpdostrumienia;
            nanumer >> ostatecznynrprzystanku;
            nanumer.str("");
            nanumer.clear();
            numerynastepnych.push_back(ostatecznynrprzystanku);
        }
        if (ajdi!=(*tempid) && fazyszukania==2) fazyszukania=3;
    }

    size_t dlugosclisty=numerynastepnych.size();
    int* tablica=new int [dlugosclisty+1];
    tablica[0]= (int) (dlugosclisty+1);
    for(int i=1;i<dlugosclisty+1;++i){
        tablica[i]=numerynastepnych.front();
        numerynastepnych.pop_front();
    }

    plik.close();
    return tablica;
}

