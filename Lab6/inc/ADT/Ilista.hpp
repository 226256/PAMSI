/*
 * Ilist.hpp
 *
 *  Created on: Mar 31, 2017
 *      Author: 226332
 */

#ifndef ILIST_HPP
#define ILIST_HPP
#include "../Wezel.hpp"
class Ilista {
public:
  // zakomentowane narazie nie używane, po co implementowac za dużo na zapas?

  /*********** Dodaj Element ************/

  // dodaje element na samym końcu listy
  virtual Ilista &dodaj(int elem) = 0;

  // dodaje element na samym początku listy
  virtual Ilista &dodaj_p(int elem) = 0;

  // dodaje element na podanym indeksie listy, jesli poza zakresem to wyjątek
  // PozaZasiegStrukutury
  // virtual void wstaw(int elem, int index)=0;

  /*********** Usuń Element ************/

  // usuwa element na samym końcu listy, jeśli nie ma, to wyjątek
  // PustaStruktura
  virtual Ilista &wysun() = 0;

  // usuwa element na samym początku listy, jeśli nie ma , to wyjątek
  // PozaZasiegStrukutury
  virtual Ilista &wysun_p() = 0;

  // usuwa gdziekolwiek chcesz
  // virtual void usun(const unsigned int && ktory)=0;

  // usuwa wszystko
  // virtual void wyczysc()=0;

  /*********** Gettery, dostęp ************/

  // zwraca zwraca obiekt po indeksie, w wypadku pustej PustaStruktura, w
  // innym to wyjątek PozaZasiegStrukutury
  // virtual int operator[](int index)=0;

  // zwraca wskaźnik na pierwszy węzeł lub Pustastruktura
  virtual Wezel *Getpierwszy() = 0;

  // zwraca wskaźnik na ostatni węzeł, jeśli itnieje tylko 1 , to na pierwszy,
  // inaczej PustaStruktura
  virtual Wezel *Getostatni() = 0;

  // zwraca rozmiar listy
  virtual unsigned int Getrozmiar() = 0;

  // destruktor wirtualny to mus
  virtual ~Ilista(){};
};

#endif
