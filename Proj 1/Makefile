#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: sortowanie
	./sortowanie

sortowanie: obj obj/main.o obj/algor.o
	g++ -Wall -pedantic -std=c++17 -o sortowanie obj/main.o obj/algor.o

obj:
	mkdir obj

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/algor.o: src/algor.cpp inc/algor.h
	g++ -c ${CXXFLAGS} -o obj/algor.o src/algor.cpp


clean:
	rm -f obj/*.o sortowanie
