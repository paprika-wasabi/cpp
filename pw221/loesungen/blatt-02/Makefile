.SUFFIXES:
.PHONY: clean compile test checkstyle


all: clean compile test checkstyle

compile: CollatzMain

test: CollatzTest
	./CollatzTest

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp *.h

clean:
	rm -f CollatzMain
	rm -f CollatzTest
	rm -f *.o

CollatzMain: Collatz.o CollatzMain.o
	g++ -o CollatzMain Collatz.o CollatzMain.o

CollatzTest: Collatz.o CollatzTest.o
	g++ -o CollatzTest Collatz.o CollatzTest.o -lgtest -lpthread

Collatz.o : Collatz.cpp Collatz.h
	g++ -c Collatz.cpp

CollatzTest.o: CollatzTest.cpp Collatz.h
	g++ -c CollatzTest.cpp

CollatzMain.o: CollatzMain.cpp Collatz.h
	g++ -c CollatzMain.cpp



