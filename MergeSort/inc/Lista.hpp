/*
 * Lista.hpp
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

#ifndef INC_LISTA_HPP_
#define INC_LISTA_HPP_
#include "ADT/Ilista.hpp"
#include "Wykonawcze/Iwykonaj.hpp"
#include "Algorytmy/Iwypelnij.hpp"
#include "Algorytmy/Iznajdz.hpp"
#include "Includy.hpp"

class Lista: public Iwykonaj,
    public Wezel,
    public Ilista,
    public Iwypelnij,
    public Iznajdz {

  Wezel *pierwszy;
  Wezel *ostatni;
  unsigned int rozmiar;

public:
  Lista() :
      pierwszy(nullptr), ostatni(nullptr), rozmiar(0){
  }
  // Ilista
  Lista &dodaj(int elem){
    Wezel *ten = ostatni;
    ++rozmiar;
    if (!pierwszy && !ostatni){
      pierwszy = new Wezel(elem);
    } else if (!ostatni){
      ostatni = new Wezel(elem, pierwszy);
    } else{
      ostatni = new Wezel(elem, ten);
    }
    return *this;
  }

  Lista &dodaj_p(int elem){
    Wezel *ten = pierwszy;
    ++rozmiar;
    if (!pierwszy && !ostatni){
      pierwszy = new Wezel(elem);
    } else if (!ostatni){
      ostatni = pierwszy;
      pierwszy = new Wezel(elem, nullptr, ten);
    } else{
      pierwszy = new Wezel(elem, nullptr, ten);
    }
    return *this;
  }

  Lista &wysun(){
    Wezel *ten = ostatni->Getpoprzedni();
    if (!ostatni){
      if (pierwszy){
        delete pierwszy;
        pierwszy = nullptr;
        return *this;
      }
      throw PustaStruktura();
    } else{
      delete ostatni;
      ostatni = ten;
    }
    return *this;
  }

  Lista &wysun_p(){
    Wezel *ten = pierwszy->Getkolejny();
    if (!pierwszy){
      if (ostatni){
        delete ostatni;
        ostatni = nullptr;
        return *this;
      }
      throw PustaStruktura();
    } else{
      delete pierwszy;
      pierwszy = ten;
    }
    return *this;
  }

  unsigned int Getrozmiar(){
    return rozmiar;
  }

  Wezel *Getpierwszy(){
    if (!pierwszy){
      throw PustaStruktura();
    }
    return pierwszy;
  }

  Wezel *Getostatni(){
    if (!pierwszy){
      throw PustaStruktura();
    }

    if (pierwszy && !ostatni){
      return pierwszy;
    }

    return ostatni;
  }

  // Iwypelnij
  void wypelnij(unsigned int ile, int czym){
    for (unsigned int i = 0; i != ile; ++i){
      dodaj(czym);
    }
  }
  // Iznajdz
  void *znajdz(int elem){

    if (!pierwszy){
      return nullptr;
    }
    Wezel *ten = pierwszy;
    while (ten->Getelement() != elem){
      ten = ten->Getkolejny();
      if (!ten){
        return nullptr;
      }
    }
    return ten;
  }
  // Iwykonaj
  // teraz wykonuje wypełnienie struktury danych o rozmiar ,a potem wyszukuje
  // element na końcu
  void wykonaj(unsigned int rozmiar, int opcja){
    znajdz(42);
  }
  void przygotuj(unsigned int rozmiar, int opcja){
    wypelnij(rozmiar, 0);
    dodaj(42);
  }

  ~Lista(){
    Wezel *ten = pierwszy;
    while (pierwszy){
      ten = ten->Getkolejny();
      delete pierwszy;
      pierwszy = ten;
    }
  }
};

#endif /* INC_LISTA_HPP_ */
