#include <iostream>
#include <cstdlib>
#include <ctime>


#include "iList.hh"
#include "iStack.hh"
#include "iQueue.hh"
#include "iClock.hh"
#include "Node.hh"
#include "Stack.hh"
#include "List.hh"
#include "Queue.hh"
#include "functions.hh"



using namespace std;


int main(){
    List mojalista;
    iClock stoper;


    unsigned int pos=1;
    for(int k=0;k<7;k++) {
        cout <<size_of_problem[k] << " elementow do przeszuania" << endl;
        for (unsigned int i = 0; i < size_of_problem[k]; i++) {
            mojalista.add(pos, 0);
        }
        pos = mojalista.size();
        mojalista.add(pos, 1);


        working(stoper, mojalista);
    }


    return 0;
}

