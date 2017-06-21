#ifndef PRACOWNIKMPK_H
#define PRACOWNIKMPK_H

#include "siec.h"

class PracownikMPK {
private:
    static int* PobierzNastepne(std::string& Arg);

public:
    class BladPrzyOdczycieDanych{};
    static void TworzTablicePrzystankow(Siec& Arg);
    static void StworzLinie(Siec&);
};

#endif // PRACOWNIKMPK_H
