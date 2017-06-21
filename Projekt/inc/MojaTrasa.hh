//
// Created by maciek on 20.06.17.
//

#ifndef PROJEKT_MOJATRASA_HH
#define PROJEKT_MOJATRASA_HH

#include "zalaczniki.hh"
#include "Przystanek.hh"
#include "Siec.hh"
#include "Rozklad.hh"

using namespace std;


struct ParaLiniaPrzystanek{
    int linia;
    char liniaznak;
    string przystanek;
};


class MojaTrasa {
private:
    list<Przystanek*> MojePrzystankiNaTrasie;

    int LiczbaPrzystankowDoPrzejechania;

    ParaLiniaPrzystanek *tablica;
    Rozklad* SprawdzCzyNieMaBezposredniego(Siec& Arg);
public:
    MojaTrasa(const list<Przystanek *> &MojePrzystankiNaTrasie);
    virtual ~MojaTrasa();

    int getLiczbaPrzystankowDoPrzejechania() const;


    ParaLiniaPrzystanek* WytyczTrase(Siec& Arg);
};


#endif //PROJEKT_MOJATRASA_HH
