#ifndef MOJATRASA_H
#define MOJATRASA_H

#include "siec.h"
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



#endif // MOJATRASA_H
