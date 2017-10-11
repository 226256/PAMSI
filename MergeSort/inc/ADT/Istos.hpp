

#ifndef ISTACK_HPP
#define ISTACK_HPP
class Istos {
public:
  /*********** Dodaj element ************/

  // dodaje element na końcu stosu
  virtual void dodaj(int elem) = 0;

  /*********** Gettery, dostęp ************/

  // zwraca rozmiar stosu
  virtual int Getrozmiar() = 0;

  // zwraca ostatni element na stosie
  virtual int Getostatni() = 0;

  /*********** Usuń element************/

  // zabiera element z końca stosu i go zwraca , jeśli nic nie ma to wyrzuca
  // wyjątek bad_function_call
  virtual int wysun() = 0;

  // destruktor wirtualny to mus
  virtual ~Istos(){};
};

#endif
