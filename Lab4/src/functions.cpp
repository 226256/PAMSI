#include "functions.hh"

/*
 * funkcja save in file jako argumenty przyjmuje
 * -stoper czyli typ iClock w ktorym sa juz jakies dane lub jesli nie ma (to byloby niepotrzbne)
 * -wybor dla ktorej struktury danych zapisujemy czasy
 *
 * zapisuje je w pliku, kazdy czas posredni w nowej linijce a sredni na koncu
 *
 *
 */

void save_in_file(iClock& data,Structure& chosen){
    std::ofstream file;

    if(chosen==lis) file.open("Lista.txt",std::ios::app);
    else if(chosen==sta) file.open("Stos.txt",std::ios::app);
    else if(chosen==que) file.open("Kolejka.txt",std::ios::app);

    if(file.good()){
        file << "\nNew serie!\n Times of algorithm: \n";
        for(unsigned int i=0;i<rep;i++){
            file << data.gTimes(i) << " s\n";
        }
        file << "Mean time of this serie: " << data.gMean();


    }
    else std::cerr << "Something went wrong, could not save in file!" << std::endl;
    file.close();
}






/*
 * funkcje working przyjmuja jako parametry:
 * -stoper(iClock) ktorym beda mierzyc czas
 * -object typu dla ktorego przeprowadzamy pomiary
 *
 */

void working(iClock& stopwatch,iList& object){
    Structure choose=lis;
    stopwatch.timekeeping(object);
    save_in_file(stopwatch,choose);
    std::cout << "Mean time of algorithm for List: " << stopwatch.gMean() << std::endl;
    stopwatch.reset();

}

void working(iClock& stopwatch,iStack& object){
    Structure choose=sta;
    stopwatch.timekeeping(object);
    save_in_file(stopwatch,choose);
    std::cout << "Mean time of algorithm for Stack: " << stopwatch.gMean() << std::endl;
    stopwatch.reset();
}



void working(iClock& stopwatch,iQueue& object){
    Structure choose=que;
    stopwatch.timekeeping(object);
    save_in_file(stopwatch,choose);
    std::cout << "Mean time of algorithm for Queue: " << stopwatch.gMean() << std::endl;
    stopwatch.reset();

}