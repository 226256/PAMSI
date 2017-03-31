
CPPFLAGS=-c -g -Iinc -Wall -Wextra -pedantic -ggdb

Work: obj/main.o obj/iStack.o obj/iList.o obj/iQueue.o obj/Stack.o
	g++ -Wall -pedantic -ggdb -o Work obj/main.o obj/iList.o obj/iStack.o obj/iQueue.o obj/Stack.o

obj/main.o: src/main.cpp inc/iList.hh inc/iStack.hh inc/iQueue.hh inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/iList.o:src/iList.cpp inc/iList.hh
	g++ ${CPPFLAGS} -o obj/iList.o src/iList.cpp


obj/iStack.o:src/iStack.cpp inc/iStack.hh
	g++ ${CPPFLAGS} -o obj/iStack.o src/iStack.cpp


obj/iQueue.o:src/iQueue.cpp inc/iQueue.hh
	g++ ${CPPFLAGS} -o obj/iQueue.o src/iQueue.cpp


obj/Stack.o:src/Stack.cpp inc/Stack.hh 
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp



obj/iClock.o:src/iClock.cpp inc/Stack.hh
	g++ ${CPPFLAGS} -o obj/i
