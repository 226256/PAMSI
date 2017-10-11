/*
 * Stos.hpp
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

#ifndef INC_STOS_HPP_
#define INC_STOS_HPP_

#include "ADT/Ilista.hpp"
#include "ADT/Istos.hpp"
#include "Wykonawcze/Iwykonaj.hpp"
#include "Algorytmy/Iwypelnij.hpp"
#include "Algorytmy/Iznajdz.hpp"
#include "Includy.hpp"
#include "Lista.hpp"
class Stos: public Istos, public Iznajdz, public Iwypelnij, public Iwykonaj {

  Lista lst;

public:
  Stos(){
  }
  // Istos
  int Getrozmiar(){
    return lst.Getrozmiar();
  }

  void dodaj(int elem){
    lst.dodaj(elem);
  }

  int Getostatni(){
    return lst.Getostatni()->Getelement();
  }

  int wysun(){
    int wysuniety = lst.Getostatni()->Getelement();
    lst.wysun();
    return wysuniety;
  }
  // Iznajdz
  void *znajdz(int elem){
    if (!lst.Getrozmiar()){
      return nullptr;
    }
    while (lst.Getostatni()->Getelement() != elem){
      this->wysun();
      if (!lst.Getpierwszy()){
        return nullptr;
      }
    }
    return lst.Getostatni();
  }
  // Iwypelnij
  void wypelnij(unsigned int ile, int czym){
    for (unsigned int i = 0; i != ile; ++i){
      dodaj(czym);
    }
  }
  // Iwykonaj
  // teraz wykonuje wypełnienie struktury danych o rozmiar ,a potem wyszukuje
  // element na końcu
  void wykonaj(unsigned int rozmiar, int opcja){
    znajdz(42);
  }

  void przygotuj(unsigned int rozmiar, int opcja){
    dodaj(42);
    wypelnij(rozmiar, 0);
  }
  ~Stos(){
  }
};

#endif /* INC_STOS_HPP_ */
