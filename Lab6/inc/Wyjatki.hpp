/*
 * Wyjatki.hpp
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

#include "Includy.hpp"
#ifndef INC_WYJATKI_HPP_
#define INC_WYJATKI_HPP_

class PustaStruktura: public std::runtime_error {
public:
  PustaStruktura() :
      runtime_error("Operacja na pustej strukturze!"){
  }
};

class PozaZasiegStruktury: public std::runtime_error {
public:
  PozaZasiegStruktury() :
      runtime_error("Operacja poza zasięgiem struktury!"){
  }
};

class NiewlasciwaStruktura: public std::runtime_error {
public:
  NiewlasciwaStruktura() :
      runtime_error("Podana Struktura danych nie istnieje!"){
  }
};

class BrakOpcjiDoFlagi: public std::runtime_error {
public:
  BrakOpcjiDoFlagi() :
      runtime_error("Brakuje opcji do podanej flagi!"){
  }
};

class NieznanaFlaga: public std::runtime_error {
public:
  NieznanaFlaga() :
      runtime_error("Nieznana flaga!"){
  }
};


class NieznanaOpcja: public std::runtime_error {
public:
  NieznanaOpcja() :
      runtime_error("Nieznana Opcja!"){
  }
};

#endif /* INC_WYJATKI_HPP_ */
