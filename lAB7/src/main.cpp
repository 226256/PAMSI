#include "../inc/work.hh"




/*Wplyw funkcje skrotu na zlozonosc odczytu
 * popatrzec na 2 funkcje skrotu:
 * -najprostrsza(z dwoch literek jakis kod ascii
 * -wybrac w literaturze
 *
 *
 *
 * Porownac zlozonosc odczytu dla roznych ilosci bucketow
 * Dla kazdej funkcji haszuajacej zmierzyc czas odczytu
 * z gwiazdka: rehaszowanie
 *
 */

using namespace std;
Wariant tablicawyborow[2]={pierwszy,drugi};


int main() {

    TabAso* uchwyt;
    Miernik moj(ilepomiarow);

    fglowna(tablicawyborow[0],uchwyt,moj);
//    fglowna(tablicawyborow[1],uchwyt,moj);
    return 0;
}