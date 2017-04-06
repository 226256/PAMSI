#include "array.hh"

/******************************************************************/
/*   It's a file for definition of methods of class array         */
/*                                                                */
/******************************************************************/


typedef int T;


void array::saveinarray(unsigned int index,T val){
    if(index<asize){
        a[index]=val;
    }
    else {
        std::cerr << "Error!\nCheck index!" << std::endl;
    }
}





T array::loadfromarray(unsigned int index){

    T temp=0;
    if(index<asize) temp=a[index];
    else std::cout << "Dont go beyond the array!" << std::endl;


    return temp;
}






bool array::more(unsigned int rozmiar){

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










bool array::fewer(unsigned int as){
    bool success;


    if(as<asize){
        T* temp=new T [as];
        for(unsigned int i=0;i<as;i++){
            a[i]=temp[i];
        }
        delete [] a;
        a=temp;
        asize=as;
        success=true;
    }
    else success=false;

    return success;

}


bool array::more1(){
  if(more(asize+1)==true){
    return true;
  }
  else return false;
}


bool array::more2n(){
  if(more(2*asize)==true){
    return true;
  }
  else return false;
}


//punkt podzialu bedzie na srodku tablicy
unsigned int array::point(unsigned int l, unsigned int r){
    return l+(r-l)/2;       //z dwoch podanych bierze srednia arytm i oddaje czesc calkowita
}



//taka funkcja swap dla naszej tablicy
void array::change_places(unsigned int i1,unsigned int i2){
    T temp;
    temp=a[i1];
    a[i1]=a[i2];
    a[i2]=temp;
}



void array::quicksort(unsigned int l, unsigned int r){
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

