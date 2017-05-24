#include "../inc/array.hh"


/******************************************************************/
/*       plik zawierajacy metody klasy tablica                    */
/*                                                                */
/******************************************************************/




tablica::tablica(){
    a=NULL;
    asize=0;
}


tablica::tablica(unsigned int rozmiar){
    Wartosc* temp=new Wartosc [rozmiar];
    asize=rozmiar;
    a=temp;


}



tablica::~tablica(){
    delete [] a;
}





//--------metody publiczne---------------



 void tablica::saveinarray(unsigned int index,Wartosc val){
    if(index<asize){
        a[index]=val;
    }
    else {
        std::cerr << "Problem z indeksem!" << std::endl;
    }
}


Wartosc tablica::loadfromarray(unsigned int index){

    Wartosc temp=0;
    if(index<asize) temp=a[index];
    else std::cout << "Nie wychodz poza tablice!" << std::endl;


    return temp;
}


 bool tablica::more1(){
     return more(asize + 1);
}


 bool tablica::more2n(){
     return more(2 * asize);
}









//--------------------------------------------




//-------------metody prywatne----------------


 bool tablica::more(unsigned int rozmiar){

  bool success;
  if(rozmiar>asize){
        Wartosc* temp=new Wartosc [rozmiar];
        for(unsigned int i=0;i<asize;i++){
            temp[i]=a[i];
        }
        a=temp;
        asize=rozmiar;
	success=true;
  }
  else{
    std::cerr << "Nie udalo sie powiekszyc tablicy!" << std::endl;
    success=false;
  }

  return success;
}





