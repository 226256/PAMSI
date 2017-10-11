/*
 * Wektor.cpp
 *
 *  Created on: Apr 18, 2017
 *      Author: 226332
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "../inc/Wektor.hpp"

// Iwykonaj
void Wektor::wykonaj(unsigned int, int opcja){
  sortprzezscalanie();
}
void Wektor::przygotuj(unsigned int rozmiar, int opcja){
  if (opcja == LOSOWO){
    wypelnij_losowo(rozmiar, 0, rozmiar, 0);
  } else{
    wypelnij(rozmiar, opcja);
  }
}
//własne
void Wektor::powieksz(const unsigned int &ile){
  amor += ile;
  int *nowa_tablica = new int[rozmiar + amor];
  for (unsigned int i = 0; i < rozmiar; ++i){
    nowa_tablica[i] = tablica[i];
  }
  delete[] tablica;
  tablica = nowa_tablica;
}

void Wektor::powieksz(const unsigned int &&ile){
  powieksz(ile);
}

void Wektor::pomniejsz(const unsigned int &ile){
  if (ile <= amor){
    amor -= ile;
    int *nowa_tablica = new int[rozmiar + amor];
    for (unsigned int i = 0; i < rozmiar; ++i){
      nowa_tablica[i] = tablica[i];
    }
    delete[] tablica;
    tablica = nowa_tablica;
  }
  throw PustaStruktura();
}

void Wektor::pomniejsz(const unsigned int &&ile){
  pomniejsz(ile);
}

Wektor::Wektor() :
    rozmiar(0), amor(0), tablica(nullptr){
}

Wektor::Wektor(Wektor &&zrodlo) :
    rozmiar(std::move(zrodlo.rozmiar)), amor(std::move(zrodlo.amor)), tablica(
        std::move(zrodlo.tablica)){
  zrodlo.tablica = nullptr;
}

Wektor::Wektor(int &&ilosc) :
    rozmiar(0), amor(ilosc){
  tablica = new int[ilosc];
}

Wektor::~Wektor(){
  delete[] tablica;
  tablica = nullptr;
}

// Iwektor

void Wektor::rezerwuj(const unsigned int &&ile){
  powieksz(ile);
}

void Wektor::odrezerwuj(const unsigned int &&ile){
  pomniejsz(ile);
}

Wektor &Wektor::dodaj(const int &&element, unsigned int ile){
  return dodaj(element, ile);
}

Wektor &Wektor::dodaj(const int &element, unsigned int ile){
  if (amor){
    tablica[rozmiar++] = element;
  } else if (ile){
    powieksz(ile);
    tablica[rozmiar++] = element;
  } else if (!ile){
    if (!rozmiar){
      powieksz(1);
    } else{
      powieksz(rozmiar);
    }
    tablica[rozmiar++] = element;
  }
  --amor;
  return *this;
}

// narazie nie potrzebne, ale wkrótce moga być
// void wstaw(int &&co,const unsigned int &&gdzie);

// void usun(const unsigned int && ktory); //odpowiednik erase

void Wektor::wyczysc(){
  rozmiar = 0;
  delete[] tablica;
  tablica = new int[amor];
}

Wektor &Wektor::wysun(){
  if (rozmiar){
    --rozmiar;
    if (rozmiar < amor){
      pomniejsz(rozmiar / 2);
    }
  } else{
    throw PustaStruktura();
  }
  return *this;
}

unsigned int Wektor::Getrozmiar() const{
  return rozmiar;
}

unsigned int Wektor::Getreserved() const{
  return rozmiar + amor;
}

unsigned int Wektor::Getamor() const{
  return amor;
}

int &Wektor::operator[](unsigned int &&index){
  if (index < rozmiar){
    return this->tablica[index];
  } else if (rozmiar){
    throw PozaZasiegStruktury();
  } else{
    throw PustaStruktura();
  }
  return this->tablica[0];
}
//Iwypisz

void Wektor::wypisz() const{
  for (unsigned int i = 0; i < rozmiar; ++i){
    std::cout << tablica[i] << " ";
  }
  std::cout << std::endl;
}

// Iwypelnij
void Wektor::wypelnij(unsigned int roz, int czym){
  if (czym == MALEJACO){
    for (unsigned int i = 0; i < roz; ++i){
      dodaj(roz-i-1);
    }
  } else if (czym == ROSNACO){
    for (unsigned int i = 0; i < roz; ++i){
      dodaj(i);
    }
  }
}

void Wektor::wypelnij_losowo(unsigned int rozmiar, int min, int max, int jak){
//rozkład równomierny, ale jest miejsce na poszerzenie
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(min, max);
  for (unsigned int i = 0; i < rozmiar; ++i){
    dodaj(dis(gen), 0);
  }
}

// Iszybkisort
void Wektor::szybkisort(int pierwszy, int ostatni, int piwotowanie){
// Obsługa parametru domyślnego, nie można go podać do deklaracji :/
  if (ostatni == 0){
    ostatni = rozmiar - 1;
  }
  int piwot = tablica[pierwszy];
  int i = pierwszy;
  int j = ostatni;
//w przypadku złego pivota używam domyślnego
  if (piwotowanie == PIERWSZY){
  } else if (piwotowanie == OSTATNI){
    piwot = tablica[ostatni];
  } else if (piwotowanie == SRODKOWY){
    piwot = tablica[(ostatni + pierwszy) / 2];
  }
  do{
    while (tablica[i] < piwot){
      i++;
    }
    while (tablica[j] > piwot){
      j--;
    }
    if (i <= j){
      zamien(i, j);
      i++;
      j--;
    }
  } while (i <= j);
  if (j > pierwszy){
    szybkisort(pierwszy, j);
  }
  if (i < ostatni){
    szybkisort(i, ostatni);
  }
}

void Wektor::sortprzezscalanie() {
    if(this->Getrozmiar()>1) {
        unsigned int srodek = (this->Getrozmiar()) / 2;
        Wektor temp1;
        for (unsigned int i = 0; i < srodek; ++i) {
            temp1.dodaj(tablica[i], 1);
        }
        unsigned rozm = this->Getrozmiar();
        Wektor temp2;
        for (unsigned int i = srodek; i < rozm; ++i) {
            temp2.dodaj(tablica[i], 1);
        }

        temp1.sortprzezscalanie();
        temp2.sortprzezscalanie();
        scalaj(temp1, temp2);
    }
}


void Wektor::scalaj(Wektor& wek1,Wektor& wek2){
     int i=0;
     int j=0;
     int g=0;
  while(i!=wek1.Getrozmiar() && j!=wek2.Getrozmiar()){
      if(wek1[i]<=wek2[j]){
          tablica[g]=wek1[i];
          ++g;
          ++i;
      }
      else{
          tablica[g]=wek2[j];
          ++g;
          ++j;
      }
  }
    while(i!=wek1.Getrozmiar()){
        tablica[g]=wek1[i];
        ++g;
        ++i;
    }
    while(j!=wek2.Getrozmiar()){
        tablica[g]=wek2[j];
        ++g;
        ++j;
    }

}


void Wektor::zamien(int pierwszy, int drugi){
  int tmp = tablica[pierwszy];
  tablica[pierwszy] = tablica[drugi];
  tablica[drugi] = tmp;
}

