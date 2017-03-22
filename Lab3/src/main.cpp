#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <ctime>

#include "array.hh"
#include "wykonywalny.hh"
#include "timer.hh"
#include "funkcje.hh"

using namespace std;


typedef int T;





int main(){
stoper Miernik;
tablica obiekt(ROZMIAR);

unsigned int problem=ROZMIARPROBLEMU;
int ilerazy=POWTORZENIA;

zawody(Miernik,obiekt,problem,ilerazy);




return 0;
}
