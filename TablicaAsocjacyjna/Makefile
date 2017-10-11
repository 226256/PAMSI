CPPFLAGS= -c -g -Iinc -Wall -ggdb -std=c++11


Lab7: obj/main.o obj/exceptions.o obj/iTabAso.o obj/Miernik.o obj/Node.o obj/TabAso.o obj/Testowalny.o obj/work.o obj/zalaczniki.o
	g++ -Wall -pedantic -ggdb -o Lab7 obj/main.o  obj/iTabAso.o obj/Miernik.o obj/Node.o obj/TabAso.o obj/Testowalny.o obj/work.o obj/zalaczniki.o obj/exceptions.o




obj/main.o: src/main.cpp inc/work.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/zalaczniki.o: inc/zalaczniki.hh 
	g++ ${CPPFLAGS} -o obj/zalaczniki.o src/zalaczniki.cpp

obj/work.o: inc/work.hh inc/zalaczniki.hh inc/iTabAso.hh inc/Miernik.hh
	g++ ${CPPFLAGS} -o obj/work.o src/work.cpp

obj/exceptions.o: inc/exceptions.hh inc/zalaczniki.hh
	g++ ${CPPFLAGS} -o obj/exceptions.o src/exceptions.cpp


obj/Node.o:  inc/Node.hh inc/zalaczniki.hh
	g++ ${CPPFLAGS} -o obj/Node.o src/Node.cpp

obj/iTabAso.o: inc/iTabAso.hh inc/zalaczniki.hh inc/Node.hh
	g++ ${CPPFLAGS} -o obj/iTabAso.o src/iTabAso.cpp


obj/Miernik.o: inc/Miernik.hh inc/zalaczniki.hh inc/iTabAso.hh
	g++ ${CPPFLAGS} -o obj/Miernik.o src/Miernik.cpp


obj/Testowalny.o: inc/Testowalny.hh inc/zalaczniki.hh
	g++ ${CPPFLAGS} -o obj/Testowalny.o src/Testowalny.cpp

obj/TabAso.o: inc/TabAso.hh inc/exceptions.hh inc/Node.hh inc/iTabAso.hh inc/Testowalny.hh
	g++ ${CPPFLAGS} -o obj/TabAso.o src/TabAso.cpp




clean:
	rm -f obj/*.o  Lab7
