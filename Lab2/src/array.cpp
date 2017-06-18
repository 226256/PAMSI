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

