/*
 * Iwykonaj.hpp
 *
 *  Created on: Mar 19, 2017
 *      Author: 226332
 */

#ifndef INC_ALGORYTM_HPP_
#define INC_ALGORYTM_HPP_

class Iwykonaj {
public:
  virtual ~Iwykonaj(){
  }
  ;
  // wykonuje zadany przez użytkownika algorytm w klasie dziedziczącej ,dla
  // rozmiaru danych "rozmiar";
  virtual void wykonaj(unsigned int rozmiar, int opcja) = 0;
  virtual void przygotuj(unsigned int rozmiar, int opcja) = 0;
};

#endif /* INC_ALGORYTM_HPP_ */
