//
// Created by maciek on 06.06.17.
//

#ifndef PROJEKT_PRACOWNIKMPK_HH
#define PROJEKT_PRACOWNIKMPK_HH

#include "zalaczniki.hh"
#include "Rozklad.hh"
#include "Przystanek.hh"
#include "Siec.hh"

class PracownikMPK {
private:
    static int* PobierzNastepne(std::string& Arg);

public:
    class BladPrzyOdczycieDanych{};
    static void TworzTablicePrzystankow(Siec& Arg);
    static void StworzLinie(Siec&);
};


#endif //PROJEKT_PRACOWNIKMPK_HH
