#include <iostream>
#include <cstdio>
#include <cstdlib>

#include <ctime>

#include "array.hh"


using namespace std;


typedef int T;


void zwiekszanie_o_1(array& Arg,unsigned int oile){
    for(unsigned int i=0;i<oile;i++){
      if(Arg.more1()==false){
	  break;
	  cerr << "Problem!" << endl;
      }
        Arg.saveinarray(Arg.sizeofarray()-1,rand()%10);
    }
}

void zwiekszanie_2_razy(array& Arg,unsigned int oile,unsigned int pierwszyrozm){
  bool success=true;
  while(Arg.sizeofarray()<pierwszyrozm+oile){
    if(Arg.more2n()==false){
      success=false;
      break;
    }
    
   }
  if(success==true){
    for(unsigned int i=pierwszyrozm;i<pierwszyrozm+oile;i++){
    Arg.saveinarray(i,rand()%10);
    }
  }
}





int main(){
clock_t start,stop;
double roznica;




unsigned int rozmiar=10;

array my(rozmiar);

cout << my.sizeofarray() <<endl;
for(unsigned int i=0;i<my.sizeofarray();i++){
    my.saveinarray(i,rand()%10);
    cout << my.loadfromarray(i) << endl;
}


start=clock();
//zwiekszanie_o_1(my,10000);
zwiekszanie_2_razy(my,1000,rozmiar);
cout << my.sizeofarray() << endl;



stop=clock();
roznica=(stop-start)/(double)CLOCKS_PER_SEC;;

cout << "Czas wykonywania: " << roznica << 's' << endl;




return 0;
}
