/*
 * Iwypelnij.hpp
 *
 *  Created on: Mar 19, 2017
 *      Author: arr
 */

#ifndef INC_WYPELNIJ_HPP_
#define INC_WYPELNIJ_HPP_
// std::fill, wersja afrykańska
#define LOSOWO 0
#define ROSNACO 1
#define MALEJACO 2

class Iwypelnij {
public:
  // wypełnia dziedziczącą strukture danych opcją "czym" o "ile" elementów
  virtual void wypelnij(unsigned int ile, int czym) = 0;
  virtual ~Iwypelnij(){
  }
  // Wypelnia losowo o 'ile' elementów i o 'jak'-metoda dystybucji
  // w wypadku niezdefiniowanej metody wyrzuca bad_function_call
  //virtual void wypelnij_losowo(unsigned int ile, int min, int max,
  //                             int jak = 0)=0;
  //virtual void wypelnij_uzytkownik()=0;
};

#endif /* INC_WYPELNIJ_HPP_ */
