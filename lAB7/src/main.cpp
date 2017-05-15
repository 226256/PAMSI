#include "../inc/zalaczniki.hh"
#include "../inc/TabAso.hh"
#include "../inc/Miernik.hh"





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

int main() {
    TabAso* uchwyt;
    bool mozna=true;
    try{
        uchwyt=new TabAso(10);
    }
    catch(bad_alloc){
        cerr << "Problem z pamiecia" << endl;
        mozna=false;
    }

    Miernik moj(ilepomiarow);

//-----szukane:
    string szukany="szukany";
    int szukany2=100;

    if(mozna) {
        for (int i = 0; i < ilepomiarow; ++i) {

            moj.mierzczas(*uchwyt, szukany,szukany2, i, pierwszy);

        }
        cout << moj.wezsredni() <<endl;
    }

    return 0;
}