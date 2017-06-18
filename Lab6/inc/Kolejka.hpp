/*
 * Kolejka.hpp
 *
 *  Created on: Apr 4, 2017
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

#ifndef INC_KOLEJKA_HPP_
#define INC_KOLEJKA_HPP_
#include "ADT/Ikolejka.hpp"
#include "ADT/Ilista.hpp"
#include "Wykonawcze/Iwykonaj.hpp"
#include "Algorytmy/Iwypelnij.hpp"
#include "Algorytmy/Iznajdz.hpp"
#include "Includy.hpp"
#include "Lista.hpp"

class Kolejka: public Ikolejka,
    public Iwypelnij,
    public Iznajdz,
    public Iwykonaj {
  Lista lst;

public:
  Kolejka(){
  }
  // Ikolejka

  int Getrozmiar(){
    return lst.Getrozmiar();
  }

  void dodaj(int elem){
    lst.dodaj(elem);
  }

  int zabierz(){
    int zabrany = lst.Getpierwszy()->Getelement();
    lst.wysun_p();
    return zabrany;
  }

  int zobacz(){
    return lst.Getostatni()->Getelement();
  }

  // Iwypelnij
  void wypelnij(unsigned int ile, int czym){
    for (unsigned int i = 0; i != ile; ++i){
      dodaj(czym);
    }
  }
  // Iznajdz
  void *znajdz(int elem){
    if (!lst.Getrozmiar()){
      return nullptr;
    }
    while (lst.Getpierwszy()->Getelement() != elem){
      zabierz();
      if (!lst.Getostatni()){
        return nullptr;
      }
    }
    return lst.Getpierwszy();
  }
  // Iwykonaj
  void wykonaj(unsigned int rozmiar, int opcja){
    znajdz(42);
  }

  void przygotuj(unsigned int rozmiar, int opcja){
    wypelnij(rozmiar, 0);
    dodaj(42);
  }

  ~Kolejka(){
  }
  ;
};

#endif /* INC_KOLEJKA_HPP_ */
