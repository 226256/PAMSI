/*
 * Iszybkisort.hpp
 *
 *  Created on: Apr 6, 2017
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

#ifndef INC_ALGORYTMY_ISZYBKISORT_HPP_
#define INC_ALGORYTMY_ISZYBKISORT_HPP_
#define PIERWSZY 0
#define OSTATNI 1
#define SRODKOWY 2

class Iszybkisort {
public:
  // Wykonuje quicksort,pierwszy-pierwszy indeks do sortowania, ostatni-ostatni
  // indeks do sortowania, jesli 0 to jest rozmiar struktury.
  virtual void szybkisort(int pierwszy = 0, int ostatni = 0,
      int piwotowanie = 0) = 0;
  virtual void sortprzezscalanie()=0;
  //swap
  virtual void zamien(int pierwszy, int drugi)=0;
  virtual ~Iszybkisort(){
  }
};

#endif /* INC_ALGORYTMY_ISZYBKISORT_HPP_ */
