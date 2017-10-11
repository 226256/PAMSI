/*
 * Kierownik.hpp
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
// Wywołanie : -s (struktura) -r (rozmiar) [-o](opcja) [-O](Opcja) [-d]
//struktura: k(kolejka) l(lista) s(Stos) w(Wektor)
//rozmiar: unsigned int
//opcja:p(piwot=pierwszy element) o(ostatni) s(srodkowy)
//Opcja:r(wypelnij rosnaco),m(wypelnij malejaco),l(wypelnij losowo)
//d: debug
#ifndef INC_WYKONAWCZE_KIEROWNIK_HPP_
#define INC_WYKONAWCZE_KIEROWNIK_HPP_

#include "../Wektor.hpp"
#include "../Stos.hpp"
#include "../Kolejka.hpp"
#include "../Includy.hpp"
#include "../Stoper.hpp"

class Kierownik {

public:
  static void kieruj(int argc, char* argv[]){
    int opt = 0;
    int rozmiar = 0;
    int opcjaP = 0;//opcja przygotowania
    int opcjaW = 0;//opcja wykonania
    bool debug=false;
    Iwykonaj *Dane = nullptr;

    while ((opt = getopt(argc, argv, "r:s:do:O:")) != -1){
      switch(opt){

        case 'r': //rozmiar
          rozmiar = atoi(optarg);
          break;

        case 's': //struktura;
          switch(*optarg){
            case 'k':
              Dane = new Kolejka();
              break;

            case 'l':
              Dane = new Lista();
              break;

            case 's':
              Dane = new Stos();
              break;

            case 'w':
              Dane = new Wektor();
              break;

            default:
              std::cerr<<"-"<<(char)opt<<" "<<optarg<<std::endl;
              throw NiewlasciwaStruktura();
          }
          break;

        case 'd': //debug, narazie nie obsługiwane
          debug=true;
          break;

        case 'O': //opcja przygotowania algorytmu
          switch(*optarg){
            case 'm':
              opcjaP = MALEJACO;
              break;

            case 'r':
              opcjaP = ROSNACO;
              break;

            case 'l':
              opcjaP = LOSOWO;
              break;

            default:
              std::cerr<<"-"<<(char)opt<<" "<<optarg<<std::endl;
              throw NieznanaOpcja();
          }
          break;
        case 'o': //opcja wykonania algorytmu
          switch(*optarg){
            case 'p':
              opcjaW = PIERWSZY;
              break;

            case 's':
              opcjaW = SRODKOWY;
              break;

            case 'o':
              opcjaW = OSTATNI;
              break;

            default:
              std::cerr<<"-"<<(char)opt<<" "<<optarg<<std::endl;
              throw NieznanaOpcja();
          }
          break;

        case '?':
          if (optopt == 'r' || optopt == 's' || optopt == 'O' || optopt == 'o'){
            throw BrakOpcjiDoFlagi();
          } else{
            std::cerr<<optopt<<std::endl;
            throw NieznanaFlaga();
          }
          break;
      }
    }if(debug){
      Wektor wek(10);
      wek.przygotuj(rozmiar,opcjaP);
      wek.wypisz();
      wek.sortprzezscalanie();
      wek.wypisz();
    }else{
    Stoper::zmierz_czas(rozmiar, *Dane, opcjaP, opcjaW);
    delete Dane;
    }
  }
};

#endif /* INC_WYKONAWCZE_KIEROWNIK_HPP_ */
