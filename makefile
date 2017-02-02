KT: driver.o Knight.o
	g++ driver.o Knight.o -o KT

Knight.o: Knight.h Knight.cpp
	g++ -c Knight.cpp
driver.o:
	g++ -c driver.cpp
clean:
	rm -f *.o
	rm KT
run:
	make clean
	make
	./KT
