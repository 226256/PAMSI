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


tablica::tablica(unsigned int rozmiar){
    T* temp=new T [rozmiar];
    asize=rozmiar;
    a=temp;


}



tablica::~tablica(){
    delete [] a;
}





//--------metody publiczne---------------



 void tablica::saveinarray(unsigned int index,T val){
    if(index<asize){
        a[index]=val;
    }
    else {
        std::cerr << "Problem z indeksem!" << std::endl;
    }
}


T tablica::loadfromarray(unsigned int index){

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



 void tablica::wykonaj_algorytm(unsigned int& rozmiar_problemu,wariant wybor){

//funkcja sprawdza ktory wariant powiekszania ma wybrac
    if(wybor==pierwszy){
    //jesli pierwszy to powiekszanie "+1"
        for(unsigned int i=0;i<rozmiar_problemu;i++){
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
        unsigned int pierwszyrozm=asize;
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
            for(unsigned int i=pierwszyrozm;i<pierwszyrozm+rozmiar_problemu;i++){
            saveinarray(i,rand()%10);
            }
        }
    }

}






//--------------------------------------------




//-------------metody prywatne----------------


 bool tablica::more(unsigned int rozmiar){

  bool success;
  if(rozmiar>asize){
        T* temp=new T [rozmiar];
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



void tablica::reset(){
    delete [] a;
    a=new T [ROZMIAR];
    asize=ROZMIAR;
}





//punkt podzialu bedzie na srodku tablicy
unsigned int tablica::point(unsigned int l, unsigned int r){
    return l+(r-l)/2;       //z dwoch podanych bierze srednia arytm i oddaje czesc calkowita
}



//taka funkcja swap dla naszej tablicy
void tablica::change_places(unsigned int i1,unsigned int i2){
    T temp;
    temp=a[i1];
    a[i1]=a[i2];
    a[i2]=temp;
}



void tablica::quicksort(unsigned int l, unsigned int r){
    unsigned int i=this->point(l,r);
    T val=a[i];
    a[i]=a[r];      //piwot
    unsigned int j=l;
    i=l;
    while(i!=r) {
        if (i < r) {
            if (a[i] < val) {
                change_places(i,j);
                j++;
            }
            i++;
        }
    }

    a[r]=a[j];
    a[j]=val;
    if(l<j-1){
        quicksort(l,j-1);
    }
    if(j+1<r){
        quicksort(j+1,r);
    }

}

