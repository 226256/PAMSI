/*
 * Wektor.hpp
 *
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

#include "ADT/Iwektor.hpp"
#include "Algorytmy/Iszybkisort.hpp"
#include "Wykonawcze/Iwykonaj.hpp"
#include "Algorytmy/Iwypelnij.hpp"
#include "Algorytmy/Iwypisz.hpp"
#include "Includy.hpp"
#include "Wyjatki.hpp"

class Wektor: public Iwektor,
    public Iszybkisort,
    public Iwykonaj,
    public Iwypelnij,
    public Iwypisz {

  unsigned int rozmiar; // ilosc elementow w tablicy
  unsigned int amor;    // ile jeszcze może pomieścić przed powiekszeniem
  int *tablica;

  void powieksz(const unsigned int &ile);

  void powieksz(const unsigned int &&ile);

  void pomniejsz(const unsigned int &ile);

  void pomniejsz(const unsigned int &&ile);

public:
  Wektor();

  Wektor(Wektor &&zrodlo);

  explicit Wektor(int &&ilosc);

  ~Wektor();

  // Iwektor

  void rezerwuj(const unsigned int &&ile) override;

  void odrezerwuj(const unsigned int &&ile) override;

  Wektor &dodaj(const int &&element, unsigned int ile = 0) override;

  Wektor &dodaj(const int &element, unsigned int ile = 0) override;

  // narazie nie potrzebne, ale wkrótce moga być
//   void wstaw(int &&co,const unsigned int &&gdzie);
//
//   void usun(const unsigned int && ktory); //odpowiednik erase

  void wyczysc() override;

  Wektor &wysun() override;

  unsigned int Getrozmiar() const override;

  unsigned int Getreserved() const override;

  unsigned int Getamor() const override;

  int &operator[](unsigned int &&index) override;

  //Iwypisz
  void wypisz() const override;

  // Iwykonaj
  void wykonaj(unsigned int rozmiar, int) override;

  void przygotuj(unsigned int rozmiar, int) override;

  // Iwypelnij
  void wypelnij(unsigned int rozmiar, int czym) override;

  void wypelnij_losowo(unsigned int rozmiar, int min, int max, int jak);

  // Iszybkisort
  void szybkisort(int pierwszy = 0, int ostatni = 0, int piwotowanie = 0)
      override;

  void zamien(int pierwszy, int drugi) override;

    void sortprzezscalanie() override;

    void scalaj(Wektor&,Wektor&);
};
