#ifndef FUNCTIONS_HH
#define FUNCTIONS_HH

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <iostream>


#include "iList.hh"
#include "iStack.hh"
#include "iQueue.hh"
#include "iClock.hh"
#include "Stack.hh"
#include "List.hh"
#include "Queue.hh"




enum Structure{lis,sta,que};
//przydatny typ wyliczeniowy ktory bedzie mi pomagal w main

void save_in_file(iClock&,Structure&);
void working(iClock & stopwatch,iList & object);
void working(iClock & stopwatch,iStack & object);
void working(iClock & stopwatch,iQueue & object);








#endif