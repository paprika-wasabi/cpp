.SUFFIXES:
.PHONY: compile checkstyle clean

CXX = g++

HEADERS = $(wildcard * .h)

all: clean compile test checkstyle

compile: Snake SnakeTest

Snake: Snake.o SnakeMain.o $(HEADERS)
	$(CXX) -o SnakeMain Snake.o SnakeMain.o -lncurses

test:
	./SnakeTest

SnakeTest: Snake.o SnakeTest.o $(HEADERS)
	$(CXX) -o SnakeTest Snake.o SnakeTest.o -lgtest -lncurses -lpthread

SnakeTest.o: SnakeTest.cpp $(HEADERS)
	$(CXX) -std=c++11 -c SnakeTest.cpp

checkstyle:
	python3 ../cpplint.py --repository=. *.cpp *.h

%.o: %.cpp $(HEADERS)
	$(CXX) -c $<

clean:
	rm -f *.o
	rm -f *Main
	rm -f *Test