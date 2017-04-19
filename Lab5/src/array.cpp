#include "array.hh"
#include "wykonywalny.hh"


/******************************************************************/
/*       plik zawierajacy metody klasy tablica                    */
/*                                                                */
/******************************************************************/


typedef int T;


tablica::tablica(){
    a=NULL;
    asize=0;
}


tablica::tablica( int rozmiar){
    T* temp=new T [rozmiar];
    asize=rozmiar;
    a=temp;


}



tablica::~tablica(){
    delete [] a;
}





//--------metody publiczne---------------



 void tablica::saveinarray( int index,T val){
    if(index<asize){
        a[index]=val;
    }
    else {
        std::cerr << "Problem z indeksem!" << std::endl;
    }
}


T tablica::loadfromarray( int index){

    T temp=0;
    if(index<asize) temp=a[index];
    else std::cout << "Nie wychodz poza tablice!" << std::endl;


    return temp;
}


 bool tablica::more1(){
  if(more(asize+1)==true){
    return true;
  }
  else return false;
}


 bool tablica::more2n(){
  if(more(2*asize)==true){
    return true;
  }
  else return false;
}



 void tablica::wykonaj_algorytm( int& rozmiar_problemu,wariant wybor){

//funkcja sprawdza ktory wariant powiekszania ma wybrac
    if(wybor==pierwszy){
    //jesli pierwszy to powiekszanie "+1"
        for( int i=0;i<rozmiar_problemu;i++){
            if(more1()==false){
            //jesli jakis blad przy powiekszaniu to konczy wszystko bo to oznacza
            //ze algorytm nie dziala poprawnie
                std::cerr << "Problem!" << std::endl;
                break;
            }
            saveinarray(sizeofarray()-1,rand()%10);
        }
    }


    else if(wybor==drugi){
    //analogicznie do pierwszego
         int pierwszyrozm=asize;
        bool success=true;
        /*tylko ze tuaj nie uzupelnia sie tablicy od razu po powiekszeniu pojedynczym
          ale po skonczonej calej robocie, wiec zanim ja uzupelnie musze sprawdzic
          czy powieksanie sie wgl udalo, wiec success bedzie mowila czy mozna faktycznie
          uzupelniac czy nie(gdyby mimo wszystko puscila grozi segmentation faultem */

        while(sizeofarray()<pierwszyrozm+rozmiar_problemu){
            if(more2n()==false){

                success=false;
                break;
            }
        }


        if(success==true){
            for( int i=pierwszyrozm;i<pierwszyrozm+rozmiar_problemu;i++){
            saveinarray(i,rand()%10);
            }
        }
    }

}






//--------------------------------------------




//-------------metody prywatne----------------


 bool tablica::more( int rozmiar){

  bool success;
  if(rozmiar>asize){
        T* temp=new T [rozmiar];
        for( int i=0;i<asize;i++){
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



void tablica::reset(){
    delete [] a;
    a=new T [ROZMIAR];
    asize=ROZMIAR;
}





//punkt podzialu bedzie na srodku tablicy
 int tablica::indpiwota( int l,  int r){
//    return (l+r)/2;       //z dwoch podanych bierze srednia arytm i oddaje czesc calkowita
//    return r;           //jako piwot oddaje ostatni element tablicy
    return l;           //jako piwot oddaje pierwszy element
}



//taka funkcja swap dla naszej tablicy
void tablica::change_places( int i1, int i2){
    T temp;
    temp=a[i1];
    a[i1]=a[i2];
    a[i2]=temp;
}




void tablica::quicksort( int lewy,  int prawy){
    int i,j;
    T piwot;

    i=indpiwota(lewy,prawy);
    piwot=a[i];
    a[i]=a[prawy];
    j=lewy;
    for(i=lewy;i<prawy;i++){
        if(a[i]<piwot){
            T temp;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            j++;
        }
    }
    a[prawy]=a[j];
    a[j]=piwot;

    if(lewy<j-1) quicksort(lewy,j-1);
    if(j+1<prawy) quicksort(j+1,prawy);
}








