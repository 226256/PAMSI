
CPPFLAGS= -c -g -Iinc -Wall -Wextra -pedantic -ggdb

__start__: tablica
	./tablica

tablica: obj/main.o obj/array.o
	g++ -Wall -pedantic -ggdb -o tablica obj/main.o obj/array.o

obj/main.o: src/main.cpp inc/array.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/array.o: src/array.cpp inc/array.hh
	g++ ${CPPFLAGS} -o obj/array.o src/array.cpp

clean:
	rm -f obj/*.o  tablica
