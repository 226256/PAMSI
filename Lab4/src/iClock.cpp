#include "iClock.hh"





void iClock::timekeeping(iList& Object){

    double* temp=new double [rep];                  //tutaj tworze tablice na poszczegolne czasy z ktorych bede pozniej liczyc srednie
    double sum=0;                                       //zmienna pomocnicza do trzymania sumy czasow

    for(unsigned int i=0;i<rep;i++){
        this->start();                                  //prosta sprawa tyle razy ile chce powtorzyc zaczynam od nacisniecia startu
        Object.do_algorithm(seeked);                          //w tym momencie rozpoczyna dzialanie algorytm
        this->stop();                                   //jak skonczy zapisujemy czas konca
        temp[i]=((this->ending)-(this->beginning))/(double)CLOCKS_PER_SEC;  //no i do tablicy wrzucamy czas w jakim ten algorytm sie zrobil
    }
    this->times=temp;           //po zrobieniu tyle razy ile chcemy wrzucamy do wskaznika w naszym stoperze adres tablicy w ktorej sa czasy

    for(unsigned int i=0;i<rep;i++){
        sum+=temp[i];   //sumujemy wszystkie poszcegolne czasy
    }
    this->mean=sum/rep;     //zeby na koncu w stoperze zapisac srednia czasow

}

//--------------------------------------------------dalsze 2 przypadki nie roznia sie niczym oprocz przyjetego obiektu-----------------------------//



void iClock::timekeeping(iQueue& Object){

    double* temp=new double [rep];
    double sum=0;

    for(unsigned int i=0;i<rep;i++){
        this->start();
        Object.do_algorithm(seeked);
        this->stop();
        temp[i]=((this->ending)-(this->beginning))/(double)CLOCKS_PER_SEC;
    }
    this->times=temp;

    for(unsigned int i=0;i<rep;i++){
        sum+=temp[i];
    }
    this->mean=sum/rep;



}


void iClock::timekeeping(iStack& Object){

    double* temp=new double [rep];
    double sum=0;

    for(unsigned int i=0;i<rep;i++){
        this->start();
        Object.do_algorithm(seeked);
        this->stop();
        temp[i]=((this->ending)-(this->beginning))/(double)CLOCKS_PER_SEC;
    }
    this->times=temp;

    for(unsigned int i=0;i<rep;i++){
        sum+=temp[i];
    }
    this->mean=sum/rep;
}


void iClock::reset(){
    this->times=NULL;
    this->mean=0;
}



double iClock::gMean(){
    return this->mean;
}


double iClock::gTimes(unsigned int& i){
    return this->times[i];
}




