#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-g -Iinc -Wall -pedantic -std=c++17

__start__: grafy
	./grafy

grafy: obj obj/main.o obj/matrix.o obj/list.o obj/BF.o
	g++ -Wall -pedantic -std=c++17 -o grafy obj/main.o obj/matrix.o obj/list.o obj/BF.o

obj:
	mkdir obj

obj/main.o: src/main.cpp 
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/matrix.o: src/matrix.cpp inc/matrix.hpp inc/graph.hpp
	g++ -c ${CXXFLAGS} -o obj/matrix.o src/matrix.cpp

obj/list.o: src/list.cpp inc/list.hpp inc/graph.hpp
	g++ -c ${CXXFLAGS} -o obj/list.o src/list.cpp
	
obj/BF.o: src/BF.cpp inc/BF.hpp
	g++ -c ${CXXFLAGS} -o obj/BF.o src/BF.cpp

clean:
	rm -f obj/*.o grafy
