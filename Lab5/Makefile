
CPPFLAGS= -c -g -Iinc -Wall -Wextra -pedantic -ggdb

__start__: tablica
	./tablica

tablica: obj/main.o obj/wykonywalny.o obj/array.o obj/timer.o obj/funkcje.o
	g++ -Wall -pedantic -ggdb -o tablica obj/main.o obj/wykonywalny.o obj/array.o  obj/timer.o obj/funkcje.o

obj/main.o: src/main.cpp inc/array.hh inc/timer.hh inc/wykonywalny.hh inc/funkcje.hh inc/wariant.h
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/array.o: src/array.cpp inc/array.hh inc/wykonywalny.hh inc/wariant.h
	g++ ${CPPFLAGS} -o obj/array.o src/array.cpp

obj/timer.o: src/timer.cpp inc/timer.hh inc/array.hh inc/wykonywalny.hh inc/wariant.h
	g++ ${CPPFLAGS} -o obj/timer.o src/timer.cpp

obj/wykonywalny.o: src/wykonywalny.cpp inc/wykonywalny.hh inc/wariant.h
	g++ ${CPPFLAGS} -o obj/wykonywalny.o src/wykonywalny.cpp
obj/funkcje.o: src/funkcje.cpp inc/funkcje.hh inc/array.hh inc/wykonywalny.hh inc/wariant.h
	g++ ${CPPFLAGS} -o obj/funkcje.o src/funkcje.cpp

clean:
	rm -f obj/*.o  tablica
