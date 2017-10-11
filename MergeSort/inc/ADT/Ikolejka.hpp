
#ifndef IQUEUE_HPP
#define IQUEUE_HPP

class Ikolejka {
public:
  /*********** Dodaj Element ************/

  // dodaje element na początku kolejki
  virtual void dodaj(int elem) = 0;

  /*********** Usuń Element ************/

  // zabiera element z końca kolejki i go zwraca , jeśli nic nie ma to wyrzuca
  // wyjątek PustaStruktura
  virtual int zabierz() = 0;

  /*********** Gettery, dostęp ************/

  // zwraca pierwszego w kolejce bez usuwania
  virtual int zobacz() = 0;

  // zwraca rozmiar kolejki
  virtual int Getrozmiar() = 0;

  // destruktor wirtualny to mus
  virtual ~Ikolejka(){};
};

#endif
