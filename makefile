#makefile

KT: driver.o Knight.o Board.o Case.o Stack.cpp LinkedList.o Controller.o
	g++ -g driver.o Knight.o Board.o LinkedList.o -o KT
Board.o: Board.h Board.cpp Knight.h
	g++ -g -c Board.cpp
Knight.o: Knight.h Knight.cpp
	g++ -g -c Knight.cpp
Case.o: Case.cpp
	g++ -g -c Case.cpp
LinkedList.o: LinkedList.h LinkedList.cpp
	g++ -g -c LinkedList.cpp
Controller.o: Controller.h Controller.cpp
	g++ -g -c Controller.cpp
driver.o: driver.cpp Stack.cpp Controller.o
	g++ -g -c driver.cpp
clean:
	rm -f *.o
	rm KT
run:
	make clean
	make
	./KT
