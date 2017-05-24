#include "../inc/work.hh"



using namespace std;

int main() {

    Wariant miejsce[3]={poczatekdrzewa,srodekdrzewa,koniecdrzewa};
    bst* uchwyt= nullptr;
    Miernik moj(ilepomiarow);

    for(int i=0;i<3;i++)fglowna(miejsce[i],uchwyt,moj);

}
