/*
 * Iwektor.hpp
 *
 *  Created on: Mar 16, 2017
 *      Author: 226332
 */

#ifndef IWEKTOR_HPP_
#define IWEKTOR_HPP_
class Iwektor {
public:
  // zakomentowane narazie nie używane, po co implementowac za dużo na zapas?
  virtual ~Iwektor(){};
  Iwektor(){};

  /*********** Dodaj element lub amortyzuj ************/

  // push_back,domyślnie amortyzuje tyle samo miejsca ile jest elementów,
  // 0=domyslnie
  virtual Iwektor &dodaj(const int &&element, unsigned int ile = 0) = 0;

  virtual Iwektor &dodaj(const int &element, unsigned int ile = 0) = 0;

  // insert
  // virtual void wstaw(T &&co,const unsigned int &&gdzie)=0;

  // dodaje do amortyzacji
  virtual void rezerwuj(const unsigned int &&ile) = 0;

  /*********** Usuń element lub amortyzacje ************/

  // erase
  // virtual void usun(const unsigned int && ktory)=0;

  // pop_back,jesli rozmiar jest mniejszy niż amortyzacja to zmiejsza ją o
  // połowę
  virtual Iwektor &wysun() = 0;

  // usuwa wszystkie elementy, pozostawia amortyzacje
  virtual void wyczysc() = 0;

  // odejmuje z amortyzacji
  virtual void odrezerwuj(const unsigned int &&ile) = 0;

  /*********** Gettery, dostęp ************/

  // Getter ilości elementów
  virtual unsigned int Getrozmiar() const = 0;

  // Getter ilości elementów+amortyzacji
  virtual unsigned int Getreserved() const = 0;

  // Getter ilości amortyzacji
  virtual unsigned int Getamor() const = 0;

  // Dostęp do elementu po indeksie
  virtual int &operator[](unsigned int &&index) = 0;
};

#endif /* IWEKTOR_HPP_ */
