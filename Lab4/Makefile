
CPPFLAGS=-c -g -Iinc -Wall -Wextra -pedantic -ggdb

Work: obj/main.o obj/iStack.o obj/iList.o obj/iQueue.o obj/Stack.o obj/Node.o obj/List.o obj/Queue.o
	g++ -Wall -pedantic -ggdb -o Work obj/main.o obj/iList.o obj/iStack.o obj/iQueue.o obj/Stack.o obj/Node.o obj/List.o obj/Queue.o

obj/main.o: src/main.cpp inc/iList.hh inc/iStack.hh inc/iQueue.hh inc/Stack.hh inc/Node.hh inc/iClock.hh inc/List.hh inc/Queue.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/iList.o:src/iStack.cpp inc/iList.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/iList.o src/iStack.cpp

obj/iStack.o:src/iStack.cpp inc/iStack.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/iStack.o src/iStack.cpp


obj/iQueue.o:src/iStack.cpp inc/iQueue.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/iQueue.o src/iStack.cpp


obj/Stack.o:src/Stack.cpp inc/Stack.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/Stack.o src/Stack.cpp

obj/List.o:src/List.cpp inc/List.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/List.o src/List.cpp

obj/Queue.o:src/Queue.cpp inc/Queue.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/Queue.o src/Queue.cpp

obj/Node.o:src/Node.cpp inc/Node.hh
	g++ ${CPPFLAGS} -o obj/Node.o src/Node.cpp

obj/iClock.o:src/iClock.cpp inc/iClock.hh
	g++ ${CPPFLAGS} -o obj/iClock.o src/iClock.cpp

clean:
	rm -f obj/*.o
