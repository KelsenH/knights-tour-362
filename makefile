#makefile

KT: driver.o Knight.o Board.o
	g++ -g driver.o Knight.o Board.o -o KT
Board.o: Board.h Board.cpp
	g++ -g -c Board.cpp
Knight.o: Knight.h Knight.cpp
	g++ -g -c Knight.cpp
driver.o:
	g++ -g -c driver.cpp
clean:
	rm -f *.o
	rm KT
run:
	make clean
	make
	./KT
