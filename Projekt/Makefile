#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++11


projekt: obj/main.o obj/Rozklad.o obj/Przystanek.o obj/Siec.o obj/PracownikMPK.o
	g++ -Wall -pedantic -o projekt obj/main.o obj/Rozklad.o obj/Przystanek.o obj/Siec.o obj/PracownikMPK.o

obj/main.o: src/main.cpp inc/zalaczniki.hh inc/Rozklad.hh inc/Przystanek.hh inc/Siec.hh inc/PracownikMPK.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/PracownikMPK.o: src/PracownikMPK.cpp inc/zalaczniki.hh inc/Rozklad.hh inc/Przystanek.hh inc/Siec.hh inc/PracownikMPK.hh
	g++ ${CPPFLAGS} -o obj/PracownikMPK.o src/PracownikMPK.cpp

obj/Siec.o: src/Siec.cpp inc/zalaczniki.hh inc/Rozklad.hh inc/Przystanek.hh inc/Siec.hh
	g++ ${CPPFLAGS} -o obj/Siec.o src/Siec.cpp

obj/Przystanek.o: src/Przystanek.cpp inc/zalaczniki.hh inc/Rozklad.hh inc/Przystanek.hh
	g++ ${CPPFLAGS} -o obj/Przystanek.o src/Przystanek.cpp

obj/Rozklad.o: src/Rozklad.cpp inc/zalaczniki.hh inc/Rozklad.hh
	g++ ${CPPFLAGS} -o obj/Rozklad.o src/Rozklad.cpp


clean:
	rm -f obj/*.o projekt
