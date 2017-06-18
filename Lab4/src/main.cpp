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
    int k=3;
        cout <<size_of_problem[k] << " elementow do przeszuania" << endl;
        for (unsigned int i = 0; i < size_of_problem[k]; i++) {
            mojalista.add(pos, 0);
        }
        pos = mojalista.size();
        mojalista.add(pos, 1);


        working(stoper, mojalista);

//    Stack mojstos;
//    Node* mojwezel;
//    for(int i=0;i<99;i++){
//        mojwezel=new Node;
//        mojstos.push(mojwezel);
//    }
//    int val=1;
//    mojwezel=new Node(val,NULL);
//    mojstos.push(mojwezel);
//
//
//    int s=mojstos.size();
//    Node** pointer=new Node* [s];
//
//    mojstos.do_algorithm(val,pointer);
//    cout << "tutaj przychodze" << endl;
//
//    for(int j=s;j>0;j--){
//        mojstos.push(pointer[j]);
//    }
//
//    mojwezel=new Node;
//    mojstos.push(mojwezel);
//    cout << mojstos.size() <<endl;
//
//    cout << "tutaj przychodze" << endl;

    return 0;
}

