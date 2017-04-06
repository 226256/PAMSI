#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <ctime>

#include "array.hh"


using namespace std;


typedef int T;



int main(){
    array mojatab(30);
    unsigned int rozm=mojatab.sizeofarray();
    for(unsigned int i=0;i<rozm;i++){
        T val=rand()%100;
        mojatab.saveinarray(i,val);
    }
    cout << rozm << endl;

    for(unsigned int i=0;i<rozm;i++) {
        T val=mojatab.loadfromarray(i);
        cout << val << endl;
    }
cout << endl << endl;

    unsigned int lewy=0;
    unsigned int prawy=rozm-1;
    mojatab.quicksort(lewy,prawy);

    for(unsigned int i=0;i<rozm;i++) {
        T val=mojatab.loadfromarray(i);
        cout << val << endl;
    }


        return 0;
}
