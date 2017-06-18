//
// Created by maciek on 27.04.17.
//

#ifndef NODE_HH
#define NODE_HH
#include <iostream>
#include <string>
#include "zalaczniki.hh"

/*w tym pliku bedzie definicja klasy Para ktora bedzie takim jakby wezlem
 *w kazdym wezle bedzie klucz z definicja
 * a w tablicy asocjacyjnej bedzie zalaczony wskaznik do takiego jednego wezla
 *
 */

class Para{
    Wartosc war;
    std::string klucz_str;
public:
    Para();
    Para(std::string,Wartosc);
    ~Para();

    std::string WezKlucz_str();
    Wartosc WezWar();
};

#endif //LAB7_NODE_HH
