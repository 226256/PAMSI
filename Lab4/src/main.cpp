#include <iostream>
#include <cstdlib>

#include "iList.hh"
#include "iStack.hh"
#include "iQueue.hh"
#include "iClock.hh"
#include "Node.hh"
#include "Stack.hh"
#include "List.hh"
#include "Queue.hh"

using namespace std;


int main(){

    List mojalista;
    Node* mojwezel;

    unsigned int k=1;
    for(int i=0;i < 5;i++){
        mojalista.add(k,i);
        mojwezel=mojalista.get(k);
        cout << mojwezel << " jego wartoosc: " << mojwezel->getElem() << endl;
    }


//    cout << "ilosc przed usuwaniem: " << mojalista.size() << endl;
//    k=1;
//    mojalista.rm(k);
//    k=3;
//    mojalista.rm(k);
//    k=0;
//    mojalista.rm(k);
    int h=0;
    mojwezel=mojalista.find(h);


    if(mojwezel!=NULL){
        cout << "wyszukany: " << mojwezel << endl;
    }
    else cout << "cos poszlo nie tak" << endl;

    cout << "ilosc po usuwaniu: " << mojalista.size() << endl;
    return 0;
}