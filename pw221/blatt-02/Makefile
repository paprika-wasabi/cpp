.SUFFIXES:
.PHONY: compile checkstyle clean

all: clean compile test checkstyle

compile: CollatzMain CollatzTest

test:
	./CollatzTest

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp *.h

clean:
	rm -f CollatzMain CollatzTest Collatz a.out
	rm -f *.o

CollatzMain: Collatz.o CollatzMain.o
	g++ -o Collatz Collatz.o CollatzMain.o
Collatz.o: Collatz.cpp Collatz.h
	g++ -c Collatz.cpp
CollatzMain.o: CollatzMain.cpp
	g++ -c CollatzMain.cpp
CollatzTest: CollatzTest.o Collatz.o Collatz.h
	g++ -o CollatzTest CollatzTest.o Collatz.o -lgtest -lpthread
CollatzTest.o: CollatzTest.cpp
	g++ -std=c++11 -c CollatzTest.cpp