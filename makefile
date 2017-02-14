#makefile

KT: driver.o Knight.o Board.o Case.o LinkedList.o
	g++ -g driver.o Knight.o Board.o LinkedList.o -o KT
Board.o: Board.h Board.cpp
	g++ -g -c Board.cpp
Knight.o: Knight.h Knight.cpp
	g++ -g -c Knight.cpp
Case.o:
	g++ -g -c Case.cpp
LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -c LinkedList.cpp
Stack.o: Stack.h Stack.cpp
	g++ -g -c Stack.cpp
driver.o:
	g++ -g -c driver.cpp
clean:
	rm -f *.o
	rm KT
run:
	make clean
	make
	./KT
